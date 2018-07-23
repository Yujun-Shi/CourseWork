import org.jnetpcap.Pcap;
import org.jnetpcap.PcapIf;
import org.jnetpcap.packet.*;
import org.jnetpcap.packet.format.FormatUtils;
import org.jnetpcap.protocol.JProtocol;
import org.jnetpcap.protocol.lan.Ethernet;
import org.jnetpcap.protocol.network.Arp;
import org.jnetpcap.protocol.network.Ip4;

import javax.swing.*;
import java.util.*;


public class IpPasser extends SwingWorker<Integer, Void> {
    private boolean working;
    private JTextArea verboArea;
    private PcapPacketHandler<String> jpacketHandler;
    private Pcap p;
    private PcapIf curdev;
    private HashMap<String, byte[]> ipMacMap;
    private LinkedList<Entry> allRoutes;
    private LinkedList<PcapPacket> packetBuffer;
    private JTextArea logArea;

    public void stopWorking() {
        working = false;
    }
    protected Integer doInBackground(){
        while(working) {
            p.loop(1, jpacketHandler, "haha");
        }
        return 0;
    }

    private void appendLog(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        logArea.append(msg + "\n");
                    }
                }
        );
    }

    private void broadCastARPPacket(String ipdst, Pcap p, byte[] curMacBytes){
        ARPPacket arp = new ARPPacket();
        String broadCastMac = "000000000000";
        String curIpHex = "0A010105";

        StringBuilder macbuilder = new StringBuilder();
        for(int i = 0; i < 6; ++i){
            macbuilder.append(String.format("%02x", curMacBytes[i]));
        }

        String[] tmp = ipdst.split("\\.");
        StringBuilder dstbuilder = new StringBuilder();
        for (int i = 0; i < tmp.length; ++i) {
            dstbuilder.append(String.format("%02x", Integer.parseInt(tmp[i])));
        }
        JPacket arpPacket = arp.createArp
                (macbuilder.toString(), curIpHex, broadCastMac, dstbuilder.toString());
        p.sendPacket(arpPacket);
    }

    private boolean checkIfMatch(Entry e, String ipAddr){
        String subnetAddr = e.subnetMask.getHostAddress();
        String[] subnetPart = subnetAddr.split("\\.");
        String[] ipPart = ipAddr.split("\\.");
        String[] dstPart = e.dstIpAddr.getHostAddress().split("\\.");
        for(int i = 0; i < 4;++i){
            int andIpPart = Integer.parseInt(subnetPart[i]) & Integer.parseInt(ipPart[i]);
            int andDstPart = Integer.parseInt(subnetPart[i]) & Integer.parseInt(dstPart[i]);
            if(andIpPart != andDstPart){
                return false;
            }
        }
        return true;
    }
    public IpPasser(PcapIf _curdev, Pcap _p, LinkedList<Entry> allRoutes_, JTextArea logArea_){
        p = _p;
        curdev = _curdev;
        working = true;
        ipMacMap = new HashMap<>();
        allRoutes = allRoutes_;
        packetBuffer = new LinkedList<>();
        logArea = logArea_;
        jpacketHandler = new PcapPacketHandler<String>()  {
            Ethernet eth = new Ethernet();
            Ip4 ipv4 = new Ip4();
            Arp arp = new Arp();
            @Override
            public void nextPacket(PcapPacket packet, String user) {
                try{
                    if(packet.hasHeader(eth)){
                        packet.getHeader(eth);
                        if(Arrays.equals(eth.destination(), curdev.getHardwareAddress())){
                            if(packet.hasHeader(ipv4)){
                                // obtain nxtHop
                                packet.getHeader(ipv4);
                                Entry res = null;
                                String dstAddr = FormatUtils.ip(ipv4.destination());
                                for(Entry e: allRoutes){
                                    // get the entry
                                    boolean ifMatch = checkIfMatch(e, dstAddr);
                                    if(ifMatch){
                                        res = e;
                                        break;
                                    }
                                }
                                if(res == null){
                                    System.out.println("no fucking way!");
                                    System.out.println(packet);
                                    return;
                                }
                                // obtain mac address
                                String nxtHop;
                                if(res.nxtHop.getHostAddress().equals("0.0.0.0")){
                                    nxtHop = FormatUtils.ip(ipv4.destination());
                                }else{
                                    nxtHop = res.nxtHop.getHostAddress();

                                }
                                if(ipMacMap.containsKey(nxtHop)){
                                    // send the packet out
                                    //source mac
                                    byte[] srcBytes = curdev.getHardwareAddress();
                                    // dst mac
                                    byte[] dstBytes = ipMacMap.get(nxtHop);
                                    packet.setByteArray(0, dstBytes);
                                    packet.setByteArray(6, srcBytes);
                                    p.sendPacket(packet);

                                    appendLog("packet send to: " + nxtHop);
                                }else{
                                    // send out an arp packet
                                    broadCastARPPacket(nxtHop, p, curdev.getHardwareAddress());
                                    // put the packet into a buffer
                                    packetBuffer.push(packet);
                                    System.out.print(packetBuffer.size());
                                }
                            }else if(packet.hasHeader(arp)){
                                if(arp.operation() == 2){ // reply
                                    byte[] sourceIpAddr = arp.spa();
                                    byte[] sourceMacAddr = arp.sha();
                                    ipMacMap.put(FormatUtils.ip(sourceIpAddr), sourceMacAddr);

                                    // print out ipMacMap for debug purpose
                                    //Iterator iter = ipMacMap.entrySet().iterator();
                                    /*
                                    while (iter.hasNext()) {
                                        Map.Entry entry = (Map.Entry) iter.next();
                                        String key = (String)entry.getKey();
                                        byte[] val = (byte[])entry.getValue();
                                        System.out.println("key: " + key + "val: " + FormatUtils.mac(val));
                                    }
                                    */
                                    byte[] srcBytes = curdev.getHardwareAddress();
                                    String sourceIpAddrStr = FormatUtils.ip(sourceIpAddr);
                                    LinkedList<PcapPacket> pingPong = new LinkedList<>();
                                    for(PcapPacket pac : packetBuffer){
                                        for(Entry e : allRoutes){
                                            pac.getHeader(ipv4);
                                            boolean ifMatch = checkIfMatch(e, FormatUtils.ip(ipv4.destination()));
                                            if(ifMatch){
                                                String nxtHop;
                                                if(e.nxtHop.getHostAddress().equals("0.0.0.0"))
                                                    nxtHop = FormatUtils.ip(ipv4.destination());
                                                else
                                                    nxtHop = e.nxtHop.getHostAddress();
                                                System.out.println("nxtHop " + nxtHop + " sourceIpAddr " + sourceIpAddrStr);
                                                if(nxtHop.equals(sourceIpAddrStr)){
                                                    // dst mac address
                                                    packet.setByteArray(0, sourceMacAddr);
                                                    packet.setByteArray(6,srcBytes);
                                                    p.sendPacket(packet);
                                                    pingPong.add(packet);
                                                    appendLog("cache packet send to: " + nxtHop);
                                                }
                                            }
                                        }
                                    }
                                    packetBuffer.removeAll(pingPong);
                                }
                            }
                        }
                    }
                }catch(Exception e){
                    e.printStackTrace();
                    System.out.println("Ip passer exception: " + e.toString() + "\n");
                }
            }
        };
    }
}

class ARPPacket {
    private static final String hardwareType = "0001";// 2 bytes
    private static final String protocolType = "0800";// IPv4 protocol
    private static final String hardwareAddressLength = "06";// xx-xx-xx-xx-xx-xx  48 bits => 6bytes
    private static final String protocolAddressLength = "04";// yyy.yyy.yyy.yyy 32 bits => 4 bytes
    private static final String operationCode = "0001";// Arp request 0001 ; Arp reply 0002

    public ARPPacket() {
        // TODO Auto-generated constructor stub
    }

    public JPacket createArp(String MAC_SOURCE, String IP_SOURCE, String MAC_DESTINATION, String IP_DESTINATION) {
        String ARPPacket = "ffffffffffff" + MAC_SOURCE + "0806"
                + hardwareType + protocolType + hardwareAddressLength + protocolAddressLength + operationCode
                + MAC_SOURCE + IP_SOURCE + MAC_DESTINATION + IP_DESTINATION;
        JPacket arpRequest = new JMemoryPacket(JProtocol.ETHERNET_ID, ARPPacket);
        // System.out.println(arpRequest);
        return arpRequest;
    }
}

