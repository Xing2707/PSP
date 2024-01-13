package Ejercicio7;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Ascensor implements Runnable,interfaceAscensor{
    private static final int MAX_BYTE = 66535;
    private static final int SLEPP_TIME = 100;
    private static final int MAX_MOVE = 10;
    public static Object llegar = new Object();
    private int codId;
    private String addressIp;
    private int puerto;
    private int codigo;
    private String piso;
    private char direccion;

    @Override
    public void config(int id, String ip, int port) {
        this.codId = id;
        this.addressIp = ip;
        this.puerto = port;
        this.codigo = 0;
        this.piso = "0";
        this.direccion = ' ';
    }

    @Override
    public synchronized void subir() {
       this.direccion = 'U';
    }

    @Override
    public synchronized void bajar() {
        this.direccion = 'D';
    }

    @Override
    public synchronized String getplanta() {
        return (Integer.parseInt(this.piso) == 0)? "PB" : this.piso;
    }

    @Override
    public synchronized String toProtocolo() {
        return null;
    }

    @Override
    public interfaceAscensor fromProtocolo(String data) {
        return null;
    }
    
    @Override
    public void run() {
        int cont = 0;
        String message;
        try {
            DatagramSocket socket = new DatagramSocket();
            DatagramPacket packet = null;
            while (true){
                byte[] data = new byte[MAX_BYTE];

                // if(cont == MAX_MOVE){
                //     if(this.direccion == 'U'){
                //         this.piso = String.valueOf((Integer.parseInt(piso)+1));
                //         message = toString();
                //     }else if(direccion == 'D'){
                //         this.piso = String.valueOf((Integer.parseInt(piso)-1));
                //         message = toString();
                //     }
                //     direccion = ' ';
                //     cont = 0;
                    // synchronized(Ascensor.llegar){
                    //     Ascensor.llegar.wait();
                    // } 
                // }
                // if(this.direccion != ' '){
                //     Thread.sleep(SLEPP_TIME);
                //     if(this.direccion == 'U'){
                //         message = "↑";
                //     }else if(direccion == 'D'){
                //         message = "↓";
                //     }
                //     cont ++;
                // }
                //Thread.sleep(SLEPP_TIME);
                message = "o";
                data = message.getBytes();
                packet = new DatagramPacket(data,data.length,InetAddress.getByName(addressIp),puerto);
                socket.send(packet);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public String toString() {
        return "Ascensor[" + this.codigo + " ; " + getplanta() + " ; " + direccion + "]";
    }
}
