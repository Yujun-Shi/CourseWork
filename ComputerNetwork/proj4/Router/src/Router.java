import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.Inet4Address;

import javax.swing.*;

import java.util.*;
import java.net.InetAddress;

import org.jnetpcap.Pcap;
import org.jnetpcap.PcapAddr;
import org.jnetpcap.PcapIf;
import org.jnetpcap.packet.format.FormatUtils;



public class Router extends JFrame{
    // UI variable
    private JPanel rightPane;
    private JPanel centerPane;
    private JPanel centerUpPane;
    private JTextArea logArea;
    private JPanel centerDownPane;
    private JTextArea routeTable;
    private JPanel southPane;
    private JPanel southUpPane;
    private JPanel InputUnit1;
    private JTextField subnetMask;
    private JPanel InputUnit2;
    private JTextField dstAddr;
    private JPanel InputUnit3;
    private JTextField nxtHop;
    private JPanel southDownPane;
    private JButton addRoute;
    private JButton delRoute;
    private JButton startRouter;
    private JButton endRouter;
    private JList<String> availableDevice;


    // action variable
    private LinkedList<Entry> allRoutes;
    private ArrayList<PcapIf> alldevs;
    private PcapIf curDev;
    private Pcap pcap;
    private Boolean if_start = false;
    private IpPasser worker;

    public Router() throws Exception{
        super("Router");

        /************
         *  UI PART
         * *********/
        // center part
        // log area
        centerUpPane = new JPanel();
        centerUpPane.setLayout(new BorderLayout());
        centerUpPane.add(new JLabel("log"), BorderLayout.NORTH);
        logArea = new JTextArea();
        logArea.setEditable(false);
        centerUpPane.add(new JScrollPane(logArea), BorderLayout.CENTER);

        // route table
        centerDownPane = new JPanel();
        centerDownPane.setLayout(new BorderLayout());
        centerDownPane.add(new JLabel("route table"), BorderLayout.NORTH);
        routeTable = new JTextArea();
        routeTable.setEditable(false);
        centerDownPane.add(new JScrollPane(routeTable), BorderLayout.CENTER);

        // south part

        // input unit 1
        InputUnit1 = new JPanel();
        InputUnit1.setLayout(new BorderLayout());
        InputUnit1.add(new JLabel("subnet mask"), BorderLayout.NORTH);
        subnetMask = new JTextField();
        InputUnit1.add(subnetMask, BorderLayout.CENTER);

        // input unit 2
        InputUnit2 = new JPanel();
        InputUnit2.setLayout(new BorderLayout());
        InputUnit2.add(new JLabel("dst addr"), BorderLayout.NORTH);
        dstAddr = new JTextField();
        InputUnit2.add(dstAddr, BorderLayout.CENTER);

        // input unit 3
        InputUnit3 = new JPanel();
        InputUnit3.setLayout(new BorderLayout());
        InputUnit3.add(new JLabel("next hop"), BorderLayout.NORTH);
        nxtHop = new JTextField();
        InputUnit3.add(nxtHop, BorderLayout.CENTER);


        southUpPane = new JPanel();
        southUpPane.setLayout(new GridLayout(1,3));
        southUpPane.add(InputUnit1);
        southUpPane.add(InputUnit2);
        southUpPane.add(InputUnit3);

        southDownPane = new JPanel();
        southDownPane.setLayout(new GridLayout(1,4));
        addRoute = new JButton("add routes");
        delRoute = new JButton("delete routes");
        startRouter = new JButton("start router");
        endRouter = new JButton("end router");
        southDownPane.add(addRoute);
        southDownPane.add(delRoute);
        southDownPane.add(startRouter);
        southDownPane.add(endRouter);
        southPane = new JPanel();
        southPane.setLayout(new GridLayout(2,1));
        southPane.add(southUpPane);
        southPane.add(southDownPane);


        centerPane = new JPanel();
        centerPane.setLayout(new GridLayout(2,1));
        centerPane.add(centerUpPane);
        centerPane.add(centerDownPane);

        rightPane = new JPanel();
        rightPane.setLayout(new BorderLayout());
        rightPane.add(centerPane, BorderLayout.CENTER);
        rightPane.add(southPane, BorderLayout.SOUTH);

        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(new GridLayout(1,2));

        /************
         *  Action part
         * *********/
        alldevs = new ArrayList<>();
        StringBuilder errbuf = new StringBuilder();
        //Getting a list of devices
        int r = Pcap.findAllDevs(alldevs, errbuf);
        if (r != Pcap.OK) {
            System.err.printf("Can't read list of devices, error is %s", errbuf
                    .toString());
            return;
        }
        int i = 0;
        String[] allDevDesc = new String[alldevs.size()];
        for (PcapIf device : alldevs) {
            String description =
                    (device.getDescription() != null) ? device.getDescription()
                            : "No description available";
            allDevDesc[i] = String.format("#%d: %s [%s]\n", i++, device.getName(), description);
        }
        availableDevice = new JList<>(allDevDesc);
        availableDevice.setVisibleRowCount(4);
        availableDevice.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        // add(leftPane);
        add(new JScrollPane(availableDevice));
        add(rightPane);
        setSize(1350,675);


        allRoutes = new LinkedList<>();
        addRoute.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try{ // check
                    InetAddress subnetMask_ = Inet4Address.getByName(subnetMask.getText());
                    InetAddress dstAddr_ = Inet4Address.getByName(dstAddr.getText());
                    InetAddress nxtHop_ = Inet4Address.getByName(nxtHop.getText());
                    Entry entry_in_ = new Entry(subnetMask_, dstAddr_, nxtHop_);
                    allRoutes.push(entry_in_);
                    appendRoutes(entry_in_);
                }catch(Exception ex){
                    System.out.println(ex.toString());
                }
            }
        });
        delRoute.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String delDstIp = dstAddr.getText();
                String delNxtHop = nxtHop.getText();
                String delSubnetMask = subnetMask.getText();
                int index = 0;
                for(Entry en : allRoutes){
                    // if the target route is found
                    if(en.dstIpAddr.getHostAddress().equals(delDstIp) &&
                            en.nxtHop.getHostAddress().equals(delNxtHop) &&
                            en.subnetMask.getHostAddress().equals(delSubnetMask))
                    {
                        allRoutes.remove(index);
                        clearRoutes();
                        for(Entry en_ : allRoutes){
                            appendRoutes(en_);
                        }
                        return;
                    }
                    ++index;
                }
            }
        });
        startRouter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int ch = availableDevice.getSelectedIndex();
                if(ch == -1) {
                    JOptionPane.showMessageDialog(null,
                            "pls select a device!", "warning",
                            JOptionPane.INFORMATION_MESSAGE);
                    return;
                }
                int snaplen = 64 * 1024;           
                int flags = Pcap.MODE_PROMISCUOUS;
                int timeout = 500;
                curDev = alldevs.get(ch);
                pcap = Pcap.openLive(curDev.getName(), snaplen, flags, timeout, errbuf);
                if (pcap == null) {
                    System.err.printf("Error while opening device for capture: "
                            + errbuf.toString());
                    return;
                }

                startRouter.setEnabled(false);
                if_start = true;
                try {
                    for (PcapAddr capAddr : curDev.getAddresses()) {
                        InetAddress subnetMask_;
                        String [] subnetMaskStrPart_;
                        String[] ipAddrStrPart_;
                        try{
                            subnetMask_ = Inet4Address.getByName(FormatUtils.ip(capAddr.getNetmask().getData()));
                            subnetMaskStrPart_ = subnetMask_.getHostAddress().split("\\.");
                            ipAddrStrPart_ = FormatUtils.ip(capAddr.getAddr().getData()).split("\\.");
                        }catch (Exception ex){
                            continue;
                        }
                        
                        String thisNetIp = "";
                        for(int i = 0; i < 4; ++i){
                            //System.out.println(ipAddrStrPart_[i]);
                            int tmp1 = Integer.valueOf(subnetMaskStrPart_[i]);
                            int tmp2 = Integer.valueOf(ipAddrStrPart_[i]);
                            int res = tmp1 & tmp2;
                            thisNetIp += res;
                            if(i != 3)
                                thisNetIp += ".";
                        }
                        
                        InetAddress dstAddr_ = Inet4Address.getByName(thisNetIp);
                        InetAddress nxtHop_ = Inet4Address.getByName("0.0.0.0");
                        Entry entry_in_ = new Entry(subnetMask_, dstAddr_, nxtHop_);
                        allRoutes.push(entry_in_);
                        appendRoutes(entry_in_);
                    }
                }catch (Exception ee){

                    System.out.println("error when adding default route!");
                    ee.printStackTrace();
                }

                worker = new IpPasser(curDev, pcap, allRoutes, logArea);
                worker.execute();
            }
        });
        endRouter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(!if_start) {
                    JOptionPane.showMessageDialog(null,
                            "no device working for now!", "warning",
                            JOptionPane.INFORMATION_MESSAGE);
                    return;
                }
                startRouter.setEnabled(true);
                if_start = false;
                worker.stopWorking();
                pcap.close();
            }
        });
    }
    private void appendRoutes(Entry en){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        String tmpEntry = en.subnetMask.getHostAddress() + " -- "
                                + en.dstIpAddr.getHostAddress() + " -- "
                                + en.nxtHop.getHostAddress();
                        routeTable.append(tmpEntry + "\n");
                    }
                }
        );
    }
    private void clearRoutes(){
        SwingUtilities.invokeLater(
                new Runnable() {
                    @Override
                    public void run() {
                        routeTable.setText("");
                    }
                }
        );
    }

    public static void main(String []args) {
        SwingUtilities.invokeLater(
                new Runnable() {
                    @Override
                    public void run() {
                        try{
                            new Router();
                        }catch(Exception e){
                            System.out.println(e.toString());
                        }
                    }
                }
        );
    }
}

// router entry
class Entry{
    public InetAddress subnetMask;
    public InetAddress dstIpAddr;
    public InetAddress nxtHop;
    public Entry(InetAddress subnetMask_, InetAddress dstIpAddr_, InetAddress nxtHop_){
        subnetMask = subnetMask_;
        dstIpAddr = dstIpAddr_;
        nxtHop = nxtHop_;
    }
}
