package Ejercicio4.otroVersion;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class servidor {
    public static final int PUERTO = 8080;
    private static final int SEGMENT_SIZE = 2;
    private static final int BYTES_SIZE = 66535;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            byte[] data = new byte[BYTES_SIZE];
            DatagramPacket recivirPacket = new DatagramPacket(data,data.length);
            System.out.println("servido preparado!");
            while (true) {
                socket.receive(recivirPacket);
                String mensaje = new String(data,0,recivirPacket.getLength());
                String[] mensajeSegmento = mensaje.split(" ");
                if(mensajeSegmento.length >= SEGMENT_SIZE){
                    InetAddress address = InetAddress.getByName(mensajeSegmento[0].split(":")[0]);
                    int puertoRecipido = Integer.parseInt(mensajeSegmento[0].split(":")[1]);
                    DatagramPacket enviarPacket = new DatagramPacket(mensajeSegmento[1].getBytes(),mensajeSegmento[1].length(),address,puertoRecipido);
                    System.out.println(String.format("mensaje de cliente: %s",mensajeSegmento[1]));
                    socket.send(enviarPacket);
                    System.out.println("mensaje recipido de servidor enviado correcto");
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
