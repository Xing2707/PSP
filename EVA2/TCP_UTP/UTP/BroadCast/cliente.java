package BroadCast;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class cliente {
    private static final int MAX_BYTE = 65535;
    public static void main(String[] args) {
        try {
            String ip = "192.168.20.255";
            DatagramSocket socket = new DatagramSocket();
            socket.setBroadcast(true);
            InetAddress address = InetAddress.getByName(ip);
            byte[] data = new byte[MAX_BYTE];
            String sendData = "hola como estas?";
            data = sendData.getBytes();

            DatagramPacket senPacket = new DatagramPacket(data, data.length,address,8000);
            socket.send(senPacket);
            socket.close();
        } catch (Exception e) {
            System.err.println(e.getMessage());
        }
    }
}
