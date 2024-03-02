package EVA2.TCP_UTP.TCP.Ejemplo;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;



public class Cliente {
    public static void main(String[] args) {
        try {
            // Socket socket = new Socket("192.168.20.104",Serve.PORT);
            Socket socket = new Socket("localhost",Serve.PORT);
            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
            outputStream.writeUTF("hola..........");
            outputStream.flush();
            socket.shutdownOutput();
            
            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
            byte[] data = inputStream.readAllBytes();
            String mesage = new String(data,0,data.length);
            System.out.println(mesage);

            outputStream.close();
            inputStream.close();
            socket.close();
            
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
