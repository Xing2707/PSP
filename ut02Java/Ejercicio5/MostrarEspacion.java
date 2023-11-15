package ut02Java.Ejercicio5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class MostrarEspacion {
    public static void main(String[] args) throws IOException {
        List <String> cmdList;
        String line;
        String lastLine;
        for(int i = 0; i < args.length; i++){
            
            cmdList = new ArrayList<>();
            cmdList.add("du");
            cmdList.add("-h");
            cmdList.add(args[i]);
            
            ProcessBuilder processBuilderdu = new ProcessBuilder(cmdList);
            Process processdu = processBuilderdu.start();
            
            BufferedReader duBufferedReader = new BufferedReader(new InputStreamReader(processdu.getInputStream()));
            
            line = null;
            lastLine = null;
            while ((line = duBufferedReader.readLine()) != null) {
                lastLine = line;
            }
            cmdList.clear();

            cmdList.add("tail");
            cmdList.add("-1");
            ProcessBuilder tailBuilder = new ProcessBuilder(cmdList);
            Process tailProcess = tailBuilder.start();
            BufferedWriter tailWriter = new BufferedWriter(new OutputStreamWriter(tailProcess.getOutputStream())); 
            tailWriter.write(lastLine);
            tailWriter.close();


            BufferedReader tailReader = new BufferedReader(new InputStreamReader(tailProcess.getInputStream()));
            line = null;
            while ((line = tailReader.readLine()) != null) {
                System.out.println(line);
            }
        }
    }
    
}
