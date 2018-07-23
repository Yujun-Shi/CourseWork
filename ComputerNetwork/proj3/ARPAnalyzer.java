import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import org.jnetpcap.Pcap;
import org.jnetpcap.PcapIf;
import org.jnetpcap.packet.JMemoryPacket;
import org.jnetpcap.packet.JPacket;
import org.jnetpcap.packet.PcapPacket;
import org.jnetpcap.packet.PcapPacketHandler;
import org.jnetpcap.protocol.JProtocol;
import org.jnetpcap.protocol.network.*;
import javax.swing.*;
import javax.swing.JOptionPane;


public class ARPAnalyzer extends JFrame {
    private JButton start;
    private JButton end;
    private JTextArea chatWindow;
    private JPanel panel;
    private JPanel leftPane;
    private JPanel leftUpPane;
    private JPanel rightPane;
    private JTextField inputIP;
    private JLabel label;

    private List<PcapIf> alldevs;
    private StringBuilder errbuf;
    private String[] allDevDesc;
    private JList<String> availableDevice;

    private WindowWorker worker;
    private Pcap pcap;
    private boolean if_start = false;
    private byte[] curIpBytes;
    private byte[] curMacBytes;
    // constructor
    public ARPAnalyzer() {
        super("capture network packet");
        alldevs = new ArrayList<>();
        errbuf = new StringBuilder();
        //Getting a list of devices
        int r = Pcap.findAllDevs(alldevs, errbuf);
        if (r != Pcap.OK) {
            System.err.printf("Can't read list of devices, error is %s", errbuf
                    .toString());
            return;
        }

        allDevDesc = new String[alldevs.size()];
        int i = 0;
        for (PcapIf device : alldevs) {
            String description =
                    (device.getDescription() != null) ? device.getDescription()
                            : "No description available";
            allDevDesc[i] = String.format("#%d: %s [%s]\n", i++, device.getName(), description);
        }

        availableDevice = new JList<>(allDevDesc);
        availableDevice.setVisibleRowCount(4);
        availableDevice.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        chatWindow = new JTextArea();
        chatWindow.setEditable(false);
        start = new JButton("start Cap");
        end = new JButton("end Cap");
        leftUpPane = new JPanel();
        leftPane = new JPanel();
        panel = new JPanel();
        rightPane = new JPanel();
        inputIP = new JTextField();
        label = new JLabel("input ip address");

        start.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        int ch = availableDevice.getSelectedIndex();
                        if(ch == -1) {
                            JOptionPane.showMessageDialog(null,
                                    "pls select a device!", "warning",
                                    JOptionPane.INFORMATION_MESSAGE);
                            return;
                        }
                        broadCastARPPacket(inputIP.getText(), ch);

                        start.setEnabled(false);
                        if_start = true;
                        worker = new WindowWorker(chatWindow, pcap, curIpBytes, inputIP.getText());
                        worker.execute();
                    }
                }
        );
        end.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        int ch = availableDevice.getSelectedIndex();

                        if(!if_start) {
                            JOptionPane.showMessageDialog(null,
                                    "no device working for now!", "warning",
                                    JOptionPane.INFORMATION_MESSAGE);
                            return;
                        }
                        start.setEnabled(true);
                        if_start = false;
                        worker.stopWorking();
                        pcap.close();
                    }
                }
        );

        panel.setLayout(new GridLayout(1,2,10,10));
        panel.setSize(1400,350);
        leftUpPane.setLayout(new GridLayout(1,2,40,40));
        leftPane.setLayout(new BorderLayout());

        leftUpPane.add(start);
        leftUpPane.add(end);
        leftPane.add(BorderLayout.NORTH,leftUpPane);
        availableDevice.setFont(availableDevice.getFont().deriveFont(15.0f));
        JScrollPane displayDevice = new JScrollPane(availableDevice);
        leftPane.add(BorderLayout.CENTER, displayDevice);

        panel.add(leftPane);
        chatWindow.setFont(chatWindow.getFont().deriveFont(20.0f));
        JScrollPane displayChat = new JScrollPane(chatWindow);

        rightPane.setLayout(new BorderLayout());
        JPanel upPane = new JPanel();
        rightPane.add(BorderLayout.NORTH,upPane);
        rightPane.add(BorderLayout.CENTER,displayChat);
        upPane.setLayout(new GridLayout(2,1));
        upPane.add(label);
        upPane.add(inputIP);
        rightPane.add(displayChat);
        panel.add(rightPane);
        add(panel);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1400,350);
    }

    public void broadCastARPPacket(String ipdst, int deviceNumber){
        ARPPacket arp = new ARPPacket();
        String broadCastMac = "000000000000";
        PcapIf curdev = alldevs.get(deviceNumber);
        curIpBytes = curdev.getAddresses().get(0).getAddr().getData();

        try {
            curMacBytes = curdev.getHardwareAddress();
        }catch(IOException io){
            System.out.println(io.toString());
        }

        StringBuilder ipbuilder = new StringBuilder();
        for(int i = 0; i < 4; ++i){
            ipbuilder.append(String.format("%02x", curIpBytes[i]));
        }

        StringBuilder macbuilder = new StringBuilder();
        for(int i = 0; i < 6; ++i){
            macbuilder.append(String.format("%02x", curMacBytes[i]));
        }

        String[] a = ipdst.split("\\.");
        StringBuilder dstbuilder = new StringBuilder();
        for (int i = 0; i < a.length; ++i) {
            dstbuilder.append(String.format("%02x", Integer.parseInt(a[i])));
        }
        JPacket arpPacket = arp.createArp
                (macbuilder.toString(), ipbuilder.toString(), broadCastMac, dstbuilder.toString());

        int snaplen = 64 * 1024;           // Capture all packets, no truncation
        int flags = Pcap.MODE_PROMISCUOUS; // capture all packets
        int timeout = 500;

        pcap = Pcap.openLive(curdev.getName(), snaplen, flags, timeout, errbuf);
        if(pcap == null){
            System.err.printf("Error when opening device: " + errbuf.toString());
            return;
        }
        pcap.sendPacket(arpPacket);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(
                new Runnable() {
                    @Override
                    public void run() {
                        new ARPAnalyzer();
                    }
                }
        );
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
        IP_SOURCE = "60606060";
        String ARPPacket = "ffffffffffff" + MAC_SOURCE + "0806"
                + hardwareType + protocolType + hardwareAddressLength + protocolAddressLength + operationCode
                + MAC_SOURCE + IP_SOURCE + MAC_DESTINATION + IP_DESTINATION;
        JPacket arpRequest = new JMemoryPacket(JProtocol.ETHERNET_ID, ARPPacket);
        System.out.println(arpRequest);
        return arpRequest;
    }
}



class WindowWorker extends SwingWorker<Integer, Void>{
    private boolean working;
    private JTextArea verboArea;
    private PcapPacketHandler<String> jpacketHandler;
    private Pcap p;
    private byte[] curIpBytes;
    private String requestIP;
    public void stopWorking() {
        working = false;
    }
    protected Integer doInBackground(){
        while(working) {
            p.loop(1, jpacketHandler, "haha");
        }
        return 0;
    }

    WindowWorker(JTextArea _v, Pcap _p, byte[] curIpBytes_, String requestIP_){
        verboArea = _v;
        working = true;
        p = _p;
        curIpBytes = curIpBytes_;
        requestIP = requestIP_;

        jpacketHandler = new PcapPacketHandler<String>()  {
            Arp arp = new Arp();
            @Override
            public void nextPacket(PcapPacket packet, String ip) {
                if(packet.hasHeader(arp)){
                    packet.getHeader(arp);
                    if(arp.operation() == 2){
                        byte[] targetIpAddr = arp.tpa();
                        byte[] sourceIpAddr = arp.spa();

                        String[] tmp = requestIP.split("\\.");
                        byte[] askIpAddr = new byte[tmp.length];
                        for(int i = 0; i < tmp.length; ++i){
                            askIpAddr[i] = (byte)Short.parseShort(tmp[i]);
                        }
                        if(Arrays.equals(askIpAddr, sourceIpAddr)){
                        //if(Arrays.equals(targetIpAddr, curIpBytes) && Arrays.equals(askIpAddr, sourceIpAddr)){
                            byte[] sourceMacAddr = arp.sha();
                            StringBuilder macAddrBuilder = new StringBuilder(18);
                            for (byte b : sourceMacAddr) {
                                if (macAddrBuilder.length() > 0)
                                    macAddrBuilder.append(':');
                                macAddrBuilder.append(String.format("%02x", b));

                            }
                            showMessage("mac address: "+macAddrBuilder.toString() + " ip address: " + requestIP);
                            working = false;
                        }
                    }
                }
            }
        };
    }
    private void showMessage(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        verboArea.append(msg + "\n");
                    }
                }
        );
    }
}

