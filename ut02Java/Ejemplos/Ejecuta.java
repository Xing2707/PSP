package ut02Java.Ejemplos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Ejecuta {
    public static void main(String args[]) throws InterruptedException, IOException{
        List <String> cmd = new ArrayList<>();
        cmd.add("./pow");
        // cmd.add("-l");
        // cmd.add("/home/usuario");
        ProcessBuilder processBuilder = new ProcessBuilder(cmd);
        Process process = processBuilder.start();

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(process.getOutputStream()));

        writer.write("9\n");
        // writer.flush();
        writer.close();
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line = null;
        while ((line =reader.readLine()) != null) {
            System.out.println(line);
        }
        process.waitFor();
    }
}
