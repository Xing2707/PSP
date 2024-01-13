package Ejercicio1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class servido {
    private static final int MAX_BYTE = 65535;
    public static final int PUERTO = 8080;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            byte[] recipido = new byte[MAX_BYTE];
            System.out.println("mensaje:");
            while (true) {
                DatagramPacket recivPacket = new DatagramPacket(recipido, recipido.length);
                socket.receive(recivPacket);
                String message = new String(recivPacket.getData(),0,recivPacket.getLength());
                System.out.println(message);
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
