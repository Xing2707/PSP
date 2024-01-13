package Ejercicio2_3;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class cliente {
    private static final int MAX_BYTE = 66535;
    private static final String OUT = "salir";
    private static final int SLEEP_TIME = 2000;

    public static void main(String[] args) {
        String input = "";
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce algo para hacer reverse de palabra");

        try {
            DatagramSocket socket = new DatagramSocket();
            InetAddress ipAddress = InetAddress.getByName("localhost");

            while (true) {
                input = sc.nextLine();
                byte[] sData = input.getBytes();
                DatagramPacket sPacket = new DatagramPacket(sData, sData.length, ipAddress, servidor.PUERTO);

                socket.send(sPacket);
                Thread.sleep(SLEEP_TIME);

                byte[] rData = new byte[MAX_BYTE];
                DatagramPacket rPacket = new DatagramPacket(rData, rData.length);
                socket.receive(rPacket);

                String messager = new String(rPacket.getData(), 0, rPacket.getLength());
                System.out.println("Mensaje invertido: " + messager);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}