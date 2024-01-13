package Ejercicio4.otroVersion;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class enviarCliente implements Runnable{
    private static final String SERVE_NAME = "localhost";
    DatagramSocket socket;
    
    public enviarCliente(DatagramSocket socket){
        this.socket = socket;
    }

    @Override
    public void run() {
        System.out.println("Introduce el mensaje");
        Scanner sc = new Scanner(System.in);
        String mensaje;
        byte[] data = null;
        if(sc.hasNextLine()){
            mensaje = sc.nextLine();
            System.out.println(String.format("tu mensaje es: %s",mensaje));
            data = mensaje.getBytes();
            
            try {
                InetAddress address = InetAddress.getByName(SERVE_NAME);
                DatagramPacket packet = new DatagramPacket(data,data.length,address,servidor.PUERTO);
                socket.send(packet);
                System.out.println("Cliente ha enviador mensaje!");
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        Thread thread = new Thread(new enviarCliente(socket));
        thread.start();
    }
}
