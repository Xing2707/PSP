package Ejercicio2_3;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class servidor {
    private static final int MAX_BYTE = 66535;
    public static final int PUERTO = 8080;
    private static final int SLEEP_TIME = 2000;

    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            DatagramPacket rPacket = null;
            DatagramPacket sPacket = null;
            byte[] rData = new byte[MAX_BYTE];
            InetAddress ipAddress = null;

            while (true) {
                rPacket = new DatagramPacket(rData, rData.length);
                socket.receive(rPacket);

                String receivedMessage = new String(rPacket.getData(), 0, rPacket.getLength());
                System.out.println("Received from client: " + receivedMessage);

                Thread.sleep(SLEEP_TIME);

                String reversedMessage = mesaggerReverser(receivedMessage);
                ipAddress = InetAddress.getByName(rPacket.getAddress().getHostAddress());
                byte[] sData = reversedMessage.getBytes();
                sPacket = new DatagramPacket(sData, sData.length, ipAddress,rPacket.getPort());
                socket.send(sPacket);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private static String mesaggerReverser(String messager) {
        StringBuilder reversedMessage = new StringBuilder();
        for (int i = messager.length() - 1; i >= 0; i--) {
            reversedMessage.append(messager.charAt(i));
        }
        return reversedMessage.toString();
    }
}