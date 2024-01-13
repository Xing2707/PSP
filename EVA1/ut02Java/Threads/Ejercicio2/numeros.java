package ut02Java.Threads.Ejercicio2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class numeros implements Runnable{
    private int num;
    private static final int MAX_NUM = 10;
    public static final String URL = "/home/usuario/DAM2/PSP/ut02Java/Threads/Ejercicio2/tabla.txt";

    public numeros(int num) {
        this.num = num;
    }

    @Override
    public void run() {
        File file = new File(URL);
        String cadena = "";
        String line;
        int newNum = 0;
        Thread.currentThread().setName("Thread" + num);
        System.out.println(Thread.currentThread().getName());
        cadena += Thread.currentThread().getName() +" ";
        for(int i = 0; i < MAX_NUM; i++){
            newNum = num * (i + 1);
            cadena += num + " x " + (i+1) + " = " + newNum + " ";
            System.out.print(newNum + " ");
            if(i == MAX_NUM - 1) System.out.println("");
        }
        try (FileWriter writer = new FileWriter(file,true);
            BufferedWriter bufferedWriter = new BufferedWriter(writer);
            PrintWriter printWriter = new PrintWriter(bufferedWriter);){
                
                printWriter.write(cadena +"\n");
        
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }
    
}
