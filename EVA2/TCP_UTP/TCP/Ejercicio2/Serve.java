package EVA2.TCP_UTP.TCP.Ejercicio2;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Serve {
    private static ServerSocket server = null;
    private static Socket socket = null;
    private static byte[] data = null;
    public static final int PORT = 1234;
    
    public static void main(String[] args) {
        try {
            server = new ServerSocket(PORT);
            while (true) {
                // socket = server.accept();
                // FileInputStream inputStream = new FileInputStream(socket.)
                // DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                // data = inputStream.readAllBytes();
                String mesage = new String(data,0,data.length);
                System.out.println(mesage);
                
                DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
                outputStream.writeUTF("Hola........");
                outputStream.flush();
                socket.shutdownOutput();
               
                // inputStream.close();
                outputStream.close();
                socket.close();
            }
        } catch (IOException e) {
            System.out.println(e);
        }
        
    }
}
