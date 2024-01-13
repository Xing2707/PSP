package ut02Java.Threads.Ejercicio2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class index {
    public static void main(String[] args) throws InterruptedException {
        File file = new File(numeros.URL);
        ArrayList<String> cmdList = new ArrayList<>();
        int num = Integer.parseInt(args[0]);
        int x = 0;
        String line = "",newLine = "";
        Thread [] numero = new Thread[num];
        if(file.exists()) file.delete();
        for(int i = 0; i < num; i++){
            x = i+1;
            numero[i] = new Thread(new numeros(x));
        }
        // Para hace concurrente deberia separar start() con join() por que si lo hace todo dentro de mismo for
        // el programa se ejecuta y tiene que espera que el programa terminal de hacer todo para ejecutar siguiente programa
        // y eso no es concurrente, concurrente es ejecutar todo el programa mismo tiempo y terminal en un tiempo teterminado.
        for(int y = 0; y < num; y++){
            numero[y].start(); 
        }
        for(int j = 0; j < num; j++){
            numero[j].join();
        }
        cmdList.add("sort");
        cmdList.add("-n");
        cmdList.add(numeros.URL);
        ProcessBuilder processBuilder = new ProcessBuilder(cmdList);
        try {
            Process process = processBuilder.start();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            while ((line = bufferedReader.readLine()) != null) {
                newLine += line + "\n";
            }
            bufferedReader.close();
            BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(numeros.URL));
            bufferedWriter.write(newLine);
            bufferedWriter.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}
