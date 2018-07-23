import java.net.*;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class UDPClient extends JFrame{
    // component section:
    private JTextField requestInput;
    private JTextArea chatWindow;
    private JScrollPane chatWindowScroll;
    private JLabel requestLabel;
    private DatagramSocket clientSocket;
    private InetAddress IPAddress;
    private int serverPort;
    // constructor
    public UDPClient(int port_){
        super("Yujun-Shi 1511201");
        serverPort = port_;
        requestInput = new JTextField();
        requestInput.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        try {
                            requestInput.setText("");
                            sendMessage(actionEvent.getActionCommand());
                        }catch(Exception e){
                            requestInput.setText("");
                            chatWindow.append("CLIENT- sending error: " + e.toString());
                        }


                        try{
                            receiveMessage();
                        }catch(Exception e){
                            chatWindow.append("CLIENT- receiving error: " + e.toString());
                        }
                    }
                }
        );

        chatWindow = new JTextArea();
        chatWindow.setEditable(false);

        requestLabel = new JLabel("request: ");

        setSize(500,225);

        getContentPane().setLayout(new GridBagLayout());
        GridBagConstraints gc = new GridBagConstraints();


        requestLabel.setPreferredSize(new Dimension(100,25));
        gc.fill = GridBagConstraints.HORIZONTAL;
        gc.gridx = 0;
        gc.gridy = 0;
        add(requestLabel, gc);

        requestInput.setPreferredSize(new Dimension(400, 25));
        gc.fill = GridBagConstraints.HORIZONTAL;
        gc.gridx = 1;
        gc.gridy = 0;
        add(requestInput, gc);

        chatWindowScroll = new JScrollPane(chatWindow);
        chatWindowScroll.setPreferredSize(new Dimension(500, 200));
        gc.fill = GridBagConstraints.HORIZONTAL;
        gc.weightx = 0.0;
        gc.gridwidth = 2;
        gc.gridx = 0;
        gc.gridy = 1;
        add(chatWindowScroll, gc);

        setVisible(true);
        pack();
    }

    // sendMessage method
    // there is no need to close the socket here
    private void sendMessage(String msg) throws Exception{
        byte[] sendData = msg.getBytes();
        clientSocket = new DatagramSocket();
        IPAddress = InetAddress.getByName("localhost");

        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, serverPort);
        clientSocket.send(sendPacket);
        showMessageClient(msg);

    }
    private void receiveMessage() throws Exception{
        clientSocket.setSoTimeout(5000);
        byte[] receiveData = new byte[2048];
        DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
        clientSocket.receive(receivePacket);
        String msg = new String(receivePacket.getData(),
                receivePacket.getOffset(), receivePacket.getLength());
        showMessageServer(msg);
    }
    private void showMessageServer(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        chatWindow.append("SERVER- " + msg + "\n");
                    }
                }
        );
    }
    private void showMessageClient(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        chatWindow.append("CLIENT- " + msg + "\n");
                    }
                }
        );
    }


    @Override
    protected void finalize(){
        clientSocket.close();
        try{
            super.finalize();
        }catch(Throwable t){
            System.out.println("something just happened: "+t.toString());
        }
    }

    // main function
    public static void main(String arg[]) throws Exception {
        UDPClient client = new UDPClient(9876);
        client.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}