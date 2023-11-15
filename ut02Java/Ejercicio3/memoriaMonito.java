package ut02Java.Ejercicio3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class memoriaMonito {
    public static void main(String args []) throws IOException{
        List<String> cmdList = new ArrayList<>();
        int number = 0;
        cmdList.add("free");
        cmdList.add("-h");
        
        for(int i = 0; i < Integer.parseInt(args[0]); i ++){
           
        
            ProcessBuilder processBuilder = new ProcessBuilder(cmdList);
            Process process = processBuilder.start();

            if((number = Integer.parseInt(args[0])) < 0){ 
                System.out.println("Error! Introduce numero");
            }else{
                try {
                    process.waitFor();
                    System.err.println("Proceso correcto");
                    Thread.sleep(1000);
                    
                    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                    String line = null;
                    
                    while ((line = bufferedReader.readLine()) != null) {
                        System.out.println(line);
                    }
                    Thread.sleep(4000);
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
        
    }
}
