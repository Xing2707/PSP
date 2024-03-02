package EjerciciosUni_Mult_Broad_Cast;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

public class broadCastEscucha {
    private static final int MAX_BYTE = 65535;
    private static final int PORT = 8000;
    private static final String DEFUALT_ID = "0.0.0.0";
    private static final String SECRE = "notepad";
    private static final String WINDOWS = "windows";
    private static final String WINDOWS_CMD = "notepad.exe";
    private static final String LINUX_CMD = "gedit";
    public static void main(String[] args) {
        try {
            DatagramSocket socke = new DatagramSocket(PORT,InetAddress.getByName(DEFUALT_ID));
            while (true) {
                byte[] receiveData = new byte[MAX_BYTE];
                DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
                socke.receive(receivePacket);
                String menssage = new String(receivePacket.getData(),0,receivePacket.getLength());
                if(menssage.toLowerCase().equals(SECRE)){
                    String cmd = null;
                    if(System.getProperty("os.name").toLowerCase().contains(WINDOWS)){
                        cmd = WINDOWS_CMD;
                        Runtime.getRuntime().exec(cmd);
                    }else{
                        cmd = LINUX_CMD;
                        ProcessBuilder processBuilder = new ProcessBuilder(cmd);
                        Process process = processBuilder.start();
                    }
                }else{
                    System.out.println(String.format("El usuario %s : %d envia mensaje: %s",
                                                        receivePacket.getAddress().getHostAddress(),receivePacket.getPort(),menssage)
                    );
                }
            }
        } catch (SocketException e) {
            System.out.println(e);
        } catch(UnknownHostException e){
            System.out.println(e);
        } catch(IOException e){
            System.out.println(e);
        }
    }
    
}
