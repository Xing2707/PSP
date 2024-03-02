package EVA2.TCP_UTP.TCP.MultiThread;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Scanner;


public class Cliente {
    public static void main(String[] args) {
        String mesage = "";
        while (true) {
            try (Socket socket = new Socket("localhost",1234)){
                DataOutputStream out = new DataOutputStream(socket.getOutputStream());
                InputStreamReader input = new InputStreamReader(System.in);
                BufferedReader readerScanner = new BufferedReader(input);
                out.writeUTF(readerScanner.readLine());
                out.flush();
                socket.shutdownOutput();

                DataInputStream in = new DataInputStream(socket.getInputStream());
                BufferedReader reader = new BufferedReader(new InputStreamReader(in));
                System.out.println(((mesage = reader.readLine()) != null)? mesage : "");

                in.close();
                out.close();
                socket.close();
            } catch (Exception e) {
                // TODO: handle exception
            }
        }
       
    }
}
