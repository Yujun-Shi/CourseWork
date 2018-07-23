import java.io.File;
import java.io.IOException;
import java.net.*;
import java.util.Date;
import java.text.*;

import javax.swing.*;

@SuppressWarnings("serial")
class UDPServerProcess extends JFrame implements Runnable{
    private DatagramSocket serverSocket;
    private JTextArea chatWindow;
    private int serverPort;
    public UDPServerProcess(int port_){
        chatWindow = new JTextArea();
        chatWindow.setEditable(false);
        add(new JScrollPane(chatWindow));
        setSize(500,250);
        setVisible(true);
        serverPort = port_;
    }

    private void showServerMessage(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        chatWindow.append("SERVER- " + msg + "\n");
                    }
                }
        );
    }

    private void showClientMessage(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        chatWindow.append("CLIENT- " + msg + "\n");
                    }
                }
        );
    }

    public void run(){
        try {
            serverSocket = new DatagramSocket(serverPort);
        }catch(SocketException e){
            showServerMessage("creating socket failed! " + e.toString());
            return;
        }
        showServerMessage("server socket initialized properly!");
        byte[] receiveData = new byte[1024];

        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date localDate;
        byte[] sendData;
        String response;
        DatagramPacket sendPacket;
        while(true){
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            try {
                serverSocket.receive(receivePacket);
            }catch(IOException e){
                showServerMessage("receiving data packet failed");
            }

            String request = new String(receivePacket.getData(),
                    receivePacket.getOffset(), receivePacket.getLength());
            String requestArg[] = request.split("\\|");
            System.out.println(requestArg[0]);

            showClientMessage("client IP: " + receivePacket.getAddress().toString()
                    + " port: " + (new Integer(serverPort)).toString());
            showClientMessage(request);

            //obtain client IP address and port
            InetAddress IPAddress = receivePacket.getAddress();
            int port  = receivePacket.getPort();
            if(requestArg[0].equals("Datepls")){
                showServerMessage("RECEIVED VALID REQUEST!");
                // obtain server local time
                localDate = new Date();
                String date = dateFormat.format(localDate);

                response = "the server date is: "+date+"\n";
                showServerMessage(response);

            }else if(requestArg[0].equals("filepls")){
                showServerMessage("RECEIVED VALID REQUEST!");
                // obtain all files
                String allFiles = "";
                File[] folder = new File(requestArg[1]).listFiles();
                for(int i = 0; i < folder.length; ++i){
                    allFiles = allFiles + folder[i].getName() + '\n';
                }

                response = "files under " + requestArg[0] + " : \n" + allFiles + '\n';
                showServerMessage(response);
            }else{
                showServerMessage("RECEIVED INVALID REQUEST!");
                response = "invalid request!";
            }

            sendData = response.getBytes();
            sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
            try {
                serverSocket.send(sendPacket);
            }catch(IOException e){
                showServerMessage("sending data packet failed " + e.toString());
            }
        }
    }
    @Override
    protected void finalize(){
        serverSocket.close();
        try{
            super.finalize();
        }catch(Throwable t){
            showServerMessage("something just happened: "+t.toString());
        }
    }
    public static void main(String args[]) throws Exception{
        UDPServerProcess p = new UDPServerProcess(9876);
        p.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        (new Thread(p)).start();
    }
}