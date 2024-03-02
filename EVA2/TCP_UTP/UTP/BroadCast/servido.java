package BroadCast;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;

public class servido {
    private static final int MAX_BYTE = 65535;
    public static final int PUERTO = 8000;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO,InetAddress.getByName("0.0.0.0"));
            byte[] recipido = new byte[MAX_BYTE];
            System.out.println("mensaje:");
            while (true) {
                DatagramPacket recivPacket = new DatagramPacket(recipido, recipido.length);
                socket.receive(recivPacket);
                SocketAddress socketAddress = recivPacket.getSocketAddress();
                String[] messages = socketAddress.toString().split(":");
                for(int i = 0; i < messages.length; i++){
                    System.out.print(String.format(" %s : ",messages[i]));
                }
                System.out.println();
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
