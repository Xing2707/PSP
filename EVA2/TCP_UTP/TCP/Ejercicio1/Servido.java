package EVA2.TCP_UTP.TCP.Ejercicio1;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Servido {
    private static ServerSocket server = null;
    private static Socket socket = null;
    public static final int PORT = 1234;
    public static void main(String[] args) {
         try {
            server = new ServerSocket(PORT);
            while (true) {
                socket = server.accept();
                DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
                String mesage = "";
                String newMesage = "";
                while ((mesage = reader.readLine()) != null) {
                    newMesage = newMesage.concat(mesage);
                }

                int vocales = contaVocal(newMesage);
                int consonates = contaConsonate(newMesage);

                DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
                outputStream.writeUTF(String.format("el texto lleva %d vocales %d consonates",vocales,consonates));
                outputStream.flush();
                socket.shutdownOutput();
               
                inputStream.close();
                outputStream.close();
                socket.close();
            }
        } catch (IOException e) {
            System.out.println(e);
        }
        
    }

    public static int contaVocal(String message){
        String newMessage = message.toLowerCase();
        int num = 0;
        for(int i = 0; i < message.length(); i++){
            if(message.charAt(i) == 'a' ||
                message.charAt(i) == 'e' ||
                message.charAt(i) == 'i' ||
                message.charAt(i) == 'o' ||
                message.charAt(i) == 'u'
            ){
                num ++;    
            }
        }
        return num;
    }
    public static int contaConsonate(String message){
        String newMessage = message.toLowerCase();
        int num = 0;
        for(int i = 0; i < message.length(); i++){
            if(message.charAt(i) != 'a' &&
                message.charAt(i) != 'e' &&
                message.charAt(i) != 'i' &&
                message.charAt(i) != 'o' &&
                message.charAt(i) != 'u' &&
                message.charAt(i) != ' '
            ){
                num ++;    
            }
        }
        return num;

    }
}
