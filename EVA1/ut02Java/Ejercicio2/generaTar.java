package ut02Java.Ejercicio2;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class generaTar {
    public static void main(String args[]) throws IOException{
        SimpleDateFormat format = new SimpleDateFormat("yyyy_MM_dd");
        Date now = new Date();
        for(int i = 0; i < args.length; i ++){
            List <String> cmdList = new ArrayList<>();
            String tarName = args[i].replace("/", "_") + "_" + format.format(now) + ".tar.gz";
            cmdList.add("tar");
            cmdList.add("-cvzf");
            cmdList.add(tarName);
            cmdList.add(args[i]);
            ProcessBuilder processBuilder = new ProcessBuilder(cmdList);
            Process process = processBuilder.start();
                        
            cmdList.clear();
            try{
                process.waitFor();
                System.out.println("Procesos creados");
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        }
        
    }
}
