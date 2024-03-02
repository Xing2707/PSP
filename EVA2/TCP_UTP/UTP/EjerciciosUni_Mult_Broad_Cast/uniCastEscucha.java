package EjerciciosUni_Mult_Broad_Cast;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class uniCastEscucha {
    private static final int PUERTO = 8000;
    private static final int MAX_BYTE = 65535;
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PUERTO);
            while (true) {
                byte[] receiveData = new byte[MAX_BYTE];
                DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
                socket.receive(receivePacket);
                int num = Integer.parseInt(new String(receivePacket.getData(),0,receivePacket.getLength()));
            
                String response = (isprimo(num))? "Si" :"No";
                System.out.println(String.format("%d %s numero primo",num,response));
                byte[] seendData = new byte[MAX_BYTE];
                seendData = response.getBytes();
                DatagramPacket seendPacket = new DatagramPacket(seendData,seendData.length,receivePacket.getAddress(),receivePacket.getPort());
                socket.send(seendPacket);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        
    }

    private static boolean isprimo(int num){
        final int BASE = 2;
        if(num <= 1){
            return false;
        }
        for(int i = BASE; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
}
