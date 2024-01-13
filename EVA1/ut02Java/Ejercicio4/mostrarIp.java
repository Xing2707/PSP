package ut02Java.Ejercicio4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class mostrarIp {
    private static final String WINDOWS = "windows";
    public static void main(String args[]) throws IOException{
        List<String> cmdList = new ArrayList<>();
        String config = (System.getProperty("os.name").toLowerCase().contains(WINDOWS))? "ipconfig" : "ifconfig";
        cmdList.add(config);
        ProcessBuilder processBuilder = new ProcessBuilder(cmdList);
        Process process = processBuilder.start();

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line = null;
        while ((line = bufferedReader.readLine()) != null) {
            System.out.println(line);
        }
    }   
}