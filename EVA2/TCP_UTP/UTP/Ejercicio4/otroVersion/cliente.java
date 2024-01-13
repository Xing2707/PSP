package Ejercicio4.otroVersion;

import java.net.DatagramSocket;

public class cliente {
    public static void main(String[] args) {
        int port;
        if(args.length > 0){
            port = Integer.parseInt(args[0]);
            try {
                DatagramSocket socket = new DatagramSocket(port);
                System.out.println("Cliente preparado!");
                
                Thread recivirThread = new Thread(new recivirCliente(socket));
                recivirThread.start();

                Thread enviarThread = new Thread(new enviarCliente(socket));
                enviarThread.start();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }else{
            System.out.println("debes indicar que puerto es en el argumento!");
        }
    }
    
}
