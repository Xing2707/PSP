package chat;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Serva {
    private static final int PORT = 8080;
    private static final int MAX_BYTE = 65535;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PORT);
            DatagramPacket packet = null;
            byte[] data = null;
            while (true) {
                data = new byte[MAX_BYTE];
                packet = new DatagramPacket(data,data.length);
                socket.receive(packet);
                String message = new String(packet.getData(),0,packet.getLength());
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        
    }
}
