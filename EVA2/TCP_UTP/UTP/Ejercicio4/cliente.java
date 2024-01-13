package Ejercicio4;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class cliente implements Runnable {
    private static final String SALIR = "salir";
    private static final int MAX_BYTE = 66535;
    private int puerto;
    private String ipAddress;

    public cliente(int puerto, String ipAddress) {
        this.puerto = puerto;
        this.ipAddress = ipAddress;
    }

    @Override
    public void run() {
        Scanner sc = new Scanner(System.in);
        try {
            DatagramSocket socket = new DatagramSocket();
            DatagramPacket recivePacket = null;
            DatagramPacket enviaPacket = null;
            byte[] reciveByte = null;
            byte[] enviaByte = null;
            InetAddress address = null;
            String mensaje = null;
            System.out.println("se inicializar chat con el servido para finalizar el chat debes introducir salir");
            do {  
                mensaje = sc.nextLine();
                enviaByte = new byte[MAX_BYTE];
                enviaByte = mensaje.getBytes();
                address = InetAddress.getByName(ipAddress);
                enviaPacket = new DatagramPacket(enviaByte,enviaByte.length,address,puerto);
                socket.send(enviaPacket);
                
                reciveByte = new byte[MAX_BYTE];
                recivePacket = new DatagramPacket(reciveByte,reciveByte.length);
                socket.receive(recivePacket);
                String mensajeRecivido = new String(recivePacket.getData(),0,recivePacket.getLength());
                System.out.println(String.format("Servidor: %s",mensajeRecivido)); 
            } while (!mensaje.toLowerCase().equals(SALIR));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
}
