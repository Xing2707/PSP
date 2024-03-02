package EVA2.TCP_UTP.TCP.Ejercicio1;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;

public class Cliente {
    public static Scanner sc = new Scanner(System.in);
    public static String mesage = "";
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost",Servido.PORT);
            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
            System.out.println("Introduce palablas para contar numero de vocales y consonates");
            mesage = sc.nextLine();
            sc.close();
            outputStream.writeUTF(mesage);
            outputStream.flush();
            socket.shutdownOutput();
            mesage = "";

            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            while ((mesage = reader.readLine()) != null) {
                System.out.println(mesage);
            }

            outputStream.close();
            inputStream.close();
            socket.close();
            
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
