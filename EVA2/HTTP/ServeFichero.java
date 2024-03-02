package EVA2.HTTP;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

//LOCALIZA EN /var/aw/html/arichivo.html leer fichero y responde fichero.

public class ServeFichero {
    private static final int PORT = 8080;
    private static final int REQUEST = 1;
    private static final String BASE_URL = "/var/www/html";
    public static void main(String[] args) {
        while (true) {
            try (ServerSocket server = new ServerSocket(PORT);) {
                Socket socket = server.accept();
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String mesage = reader.readLine();
                String[] newMesage = mesage.split(" ");
                String header ="";
                String body ="";
                System.out.println(mesage);
                System.out.println(newMesage[REQUEST]);
                
                File file = new File(BASE_URL + newMesage[1]);
                if(file.exists()){
                    Scanner sc = new Scanner(file);
                    while (sc.hasNextLine()) {
                        body += sc.nextLine() + "\n";
                    }
                    header = "HTTP/1.1 200 OK\n";
                }else{
                    header = "HTTP/1.1 404 No File Found\n";
                    body ="<h1>Error Archivo no encotrado!</h1>";
                }
                BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
                writer.write(header);
                writer.write("\n");
                writer.write(body);
                writer.flush();

                writer.close();
                reader.close();
                socket.close();
            } catch (Exception e) {
                new Throwable(e.getMessage());
            }
        }
    }
    
}
