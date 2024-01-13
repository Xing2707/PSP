package Ejercicio4;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class servidor implements Runnable{
    private static final int MAX_BYTE = 66535;
    private int puerto;
    public servidor(int puerto) {
        this.puerto = puerto;
    }

    @Override
    public void run() {
        try {
            DatagramSocket socket = new DatagramSocket(puerto);
            DatagramPacket recivePacket = null;
            DatagramPacket enviaPacket = null;
            byte[] reciveByte = null;
            byte[] enviaByte = null;
            InetAddress address = null;
            while (true) {
                reciveByte = new byte[MAX_BYTE];
                recivePacket = new DatagramPacket(reciveByte, reciveByte.length);
                socket.receive(recivePacket);
                String mensajeRecivido = new String(recivePacket.getData(),0,recivePacket.getLength());
                System.out.println(String.format("Cliente: %s",mensajeRecivido));

                enviaByte = new byte[MAX_BYTE];
                enviaByte = mensajeRecivido.getBytes();
                address = InetAddress.getByName(recivePacket.getAddress().getHostAddress());
                enviaPacket = new DatagramPacket(enviaByte,enviaByte.length,address,recivePacket.getPort());
                socket.send(enviaPacket);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        
        
    }
    
}
