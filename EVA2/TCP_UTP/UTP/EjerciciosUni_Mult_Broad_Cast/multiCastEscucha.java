package EjerciciosUni_Mult_Broad_Cast;

import java.lang.reflect.Array;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.MulticastSocket;
import java.net.NetworkInterface;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;
import java.util.Scanner;

public class multiCastEscucha {
    private static Scanner sc = new Scanner(System.in);
    private static final int PORT = 8000;
    private static final int MAX_BYTE = 65535;
    public static void main(String[] args) {
        byte[] receiveData = null;
        byte[] respontData = null;
        DatagramPacket receivePacket = null;
        DatagramPacket respontPacket = null;
        ArrayList<String> menssages = new ArrayList<String>();

        try{
            Enumeration<NetworkInterface> enumNet = NetworkInterface.getNetworkInterfaces();
            for (NetworkInterface interfacel : Collections.list(enumNet)){
                System.out.println(interfacel);
            }
            System.out.println("Introduce nombre de interfaz de red");
            String name = sc.nextLine();
            NetworkInterface netI = NetworkInterface.getByName(name);

            InetAddress address = InetAddress.getByName("230.0.0.10");
            InetSocketAddress socketAddress = new InetSocketAddress(address,PORT);
            MulticastSocket multiSocket = new MulticastSocket(PORT);
            while (true) {
                multiSocket.joinGroup(socketAddress, netI);

                receiveData = new byte[MAX_BYTE];
                receivePacket = new DatagramPacket(receiveData,receiveData.length);
                multiSocket.receive(receivePacket);
                
                if(sc.hasNext()){
                    while (sc.hasNext()){
                        String menssage = new String(receivePacket.getData(),0,receivePacket.getLength());
                        menssages.add(menssage);
                    }
                }else{
                    String menssage = new String(receivePacket.getData(),0,receivePacket.getLength());
                    menssages.add(menssage);
                }
                
                for(String value : menssages){
                    System.out.println(String.format("el usuario %s : %d ha escrito: %s",
                                                        receivePacket.getAddress().getHostAddress(),receivePacket.getPort(),value)
                    );
                }
                menssages.clear();
                System.out.println("Respondele algo");
                String respont = sc.nextLine();
                respontData = new byte[MAX_BYTE];
                respontPacket = new DatagramPacket(respontData,respontData.length,socketAddress);
                multiSocket.send(respontPacket);
            }

            
        }catch(Exception e){
            System.out.println(e);
        }
    }
    
    
}
