package Ejercicio4.otroVersion;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class recivirCliente implements Runnable{
    private static final int DATA_SIZE = 66535;
    DatagramPacket receivPacket;
    byte[] data;
    DatagramSocket socket;
    
    public recivirCliente(DatagramSocket socket){
        this.socket = socket;
        data = new byte[DATA_SIZE];
        receivPacket = new DatagramPacket(data,data.length);
    }
    
    @Override
    public void run() {
        try {
            socket.receive(receivPacket);
            String mensaje = new String(data,0,data.length);
            System.out.println(String.format("has recivido el mensaje: %s",mensaje));
            
            Thread thread = new Thread(new recivirCliente(socket));
            thread.start();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        
    }
}
