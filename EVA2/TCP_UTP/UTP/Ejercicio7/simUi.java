package Ejercicio7;

import java.util.Scanner;

public class simUi {
    private static final int MAX_NUM = 2;
    private int data;
    public void pintaMenu(){
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Selecciona el accion: \n1.Subir\n2.Bajar");
            this.data = sc.nextInt();
            if(this.data <= 0 || data > MAX_NUM) System.out.println("Error! Introduce numero de seleccion correcto!");
        } while (data <= 0 || data > MAX_NUM);
        
    };
    public int obtenerSeleccion(){
        return this.data;
    };
}
