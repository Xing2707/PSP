package Ejercicio1;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.net.InetAddress;

public class cliente {
    private static final int MAX_BYTE = 65535;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket();
            InetAddress address = InetAddress.getByName("localhost");
            byte[] data = new byte[MAX_BYTE];
            String sendData = "hola como estas?";
            data = sendData.getBytes();

            DatagramPacket senPacket = new DatagramPacket(data, data.length,address,servido.PUERTO);
            socket.send(senPacket);
            socket.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
