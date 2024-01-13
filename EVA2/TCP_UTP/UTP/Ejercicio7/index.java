package Ejercicio7;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

import javax.xml.crypto.Data;

public class index {
    private static final int MAX_BYTE = 66535;
    private static final int PUERTO = 8081;
    public static void main(String[] args) {
        simUi s1 = new simUi();
        Ascensor ac1 = new Ascensor();
        ac1.config(1,"127.0.0.1", PUERTO);
        Thread t1 = new Thread(ac1);
        t1.start();

        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            while (true) {
                byte[] data = new byte[MAX_BYTE];
                DatagramPacket packet = new DatagramPacket(data,data.length);
                socket.receive(packet);
                String mensaje = new String(packet.getData(),0,packet.getLength());
                System.out.println(mensaje);

                // Thread.sleep(1500);
                // s1.pintaMenu();
                // if(s1.obtenerSeleccion() == 1){
                //     ac1.subir();
                // }else{
                //     ac1.bajar();
                // }
                // synchronized(Ascensor.llegar){
                //     Ascensor.llegar.notifyAll();
                // }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
