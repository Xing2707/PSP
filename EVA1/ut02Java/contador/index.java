package ut02Java.contador;

import java.util.Scanner;

public class index {
    public static void main(String[] args) {
        contador c1 = new contador();
        Thread t1 = new Thread(c1);
        Scanner sc = new Scanner(System.in);
        String cadena;
        t1.start();
        do {
            cadena = sc.nextLine();
            t1.interrupt();
        } while (!cadena.toLowerCase().equals("s"));
        c1.parar();
        try {
            t1.join();
        } catch (InterruptedException e) {
            
        }
    }
}
