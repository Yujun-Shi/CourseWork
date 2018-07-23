import java.io.*;
import java.lang.*;
import java.net.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.logging.*;
import javax.swing.*;

public class Webserver{
    
    public static void main(String argv[]) throws Exception
    {
        // set the port number
        int port = 8000;

        HttpRequest request = new HttpRequest(port);
        request.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        new Thread(request).start();
    }
}

class HttpRequest extends JFrame implements Runnable{
    // UI part
    private JTextArea chatWindow;

    // data part
    private ServerSocket listen;
    private Socket connection;
    int port;
    // carriage return(CR) and line feed(LF)
    final static String CRLF = "\r\n";
    private FileHandler logHandler;
    Logger logger = Logger.getLogger(HttpRequest.class.getName());

    private BufferedReader br = null;
    private DataOutputStream os = null;
    private FileInputStream fis = null;

    public HttpRequest(int port_) throws Exception{
        port = port_;
        chatWindow = new JTextArea();
        chatWindow.setEditable(false);
        add(new JScrollPane(chatWindow));
        setSize(500,250);
        setVisible(true);
    }
    // UI methods
    private void showMessage(final String msg){
        SwingUtilities.invokeLater(
                new Runnable(){
                    public void run(){
                        chatWindow.append(msg + "\n");
                    }
                }
        );
    }

    // data method
    public void run() {
        try{
            listen = new ServerSocket(port);
            while(true){
                connection = listen.accept();
                showMessage("connection establisged: " + connection.getInetAddress().toString());
                processRequest();
            }
        }catch(Exception e){
            System.out.println(e.toString());
            logger.warning(e.toString());
            e.printStackTrace();
            System.out.println("It's actually an exception!");
        }
    }

    private void processRequest() throws Exception {
        // set up connection
        SimpleDateFormat format = new SimpleDateFormat("M-d_HHmmss");
        logHandler = new FileHandler("log-" + connection.getInetAddress().getHostAddress() + ".log",true);
        logHandler.setFormatter(new SimpleFormatter());
        logger.addHandler(logHandler);
        logger.info(format.format(Calendar.getInstance().getTime()));
        showMessage(format.format(Calendar.getInstance().getTime()));

        // set up all these stream
        InputStream is = connection.getInputStream();
        br = new BufferedReader(new InputStreamReader(is));
        os = new DataOutputStream(connection.getOutputStream());

        String requestLine = br.readLine();
        logger.info(requestLine);
        showMessage(requestLine);

        StringTokenizer tokens = new StringTokenizer(requestLine);
        // skip over the method, which should be GET
        tokens.nextToken();
        String fileName = tokens.nextToken();
        
        // put on a "." so the request is within the folder
        fileName = "." + fileName;

        boolean fileExists = true;
        try{
            fis = new FileInputStream(fileName);
        }catch(FileNotFoundException e){
            fileExists = false;
        }

        // construct the response message
        String statusLine = null;
        String contentTypeLine = null;
        String entityBody = null;

        if(fileExists){
            statusLine = "HTTP/1.1 200 OK" + CRLF;
            contentTypeLine = "Content-type:"+contentType(fileName) + CRLF;
        }else{
            statusLine = "HTTP/1.1 404 NOT FOUND"+CRLF;
            contentTypeLine = "Content-type: " + "text/html" + CRLF;
            entityBody = "<HTML>" + 
                "<HEAD><TITLE>NOT FOUND</TITLE></HEAD>" + 
                "<BODY>NOT FOUND</BODY></HTML>";
        }
        
        // send out the header
        os.writeBytes(statusLine);
        os.writeBytes(contentTypeLine);
        os.writeBytes(CRLF);
        logger.info(statusLine);
        logger.info(contentTypeLine);
        showMessage(statusLine);
        showMessage(contentTypeLine);

        // send out the entity body
        if(fileExists){
            logger.info("send data");
            showMessage("send data");
            sendBytes(fis, os);
            logger.info("send data finish");
            showMessage("send data finish");
            os.writeBytes(statusLine);
            fis.close();
        }else{
            os.writeBytes(statusLine);
            os.writeBytes(entityBody);
            os.writeBytes(contentTypeLine);
            logger.severe(statusLine);
            logger.severe("file not exists");
            showMessage(statusLine);
            showMessage("file not exists");
        }
        logger.removeHandler(logHandler);
        os.close();
        br.close();
        logHandler.close();
        connection.close();
    }

    private static String contentType(String fileName){
        if(fileName.endsWith(".htm") || fileName.endsWith(".html")) { return "text/html"; }
        if(fileName.endsWith(".jpg") || fileName.endsWith(".jpeg")) { return "image/jpeg"; }
        if(fileName.endsWith(".gif")) { return "image/gif"; }
        if(fileName.endsWith(".ico")) { return "image/x-icon"; }
        return "other";
    }
    
    private static void sendBytes(FileInputStream fis, OutputStream os) throws Exception{
        byte [] buffer = new byte[1024];
        int bytes = 0;

        bytes = fis.read(buffer);
        while( bytes != -1 ) {
            os.write(buffer, 0, bytes);
            bytes = fis.read(buffer);
        }
    }

    @Override
    protected void finalize() {
        try{
            super.finalize();
        }catch(Throwable t){
            showMessage("something just happened: "+t.toString());
        }
    }
}
