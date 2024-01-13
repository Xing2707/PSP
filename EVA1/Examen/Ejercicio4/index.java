package Examen.Ejercicio4;

import java.util.Scanner;

public class index {
    public static final int TOTAL_CORRIDO = 1000;
    public static final int AVANZA = 50;
    private static final int EXITO = 3;

    public static void main(String[] args) throws InterruptedException {
        cohetes cohete = new cohetes(AVANZA, args);
        Object propulsores = new Object();
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduce numero de cohetes");
        int num = sc.nextInt();
        Thread[] t = new Thread[num];
        for(int i = 0; i < num; i++){
            t[i] = new Thread(cohete);
        }

        for(int i = 0; i < num; i++){
            t[i].start();
        }
        
        for(int i = 0; i < num; i++){
            t[i].join();
        }
        System.out.println(String.format("han llegado : %d cohetes",cohete.getCont_llega()));
        System.out.println(String.format("han fallado : %d cohetes",cohete.getCont_falla()));
        if(cohete.getCont_llega() >= EXITO ){
            System.out.println("La mision ha sido exito");
        }

    }
}
