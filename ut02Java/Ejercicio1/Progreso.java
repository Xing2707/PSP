import java.io.*;
import java.util.*;
class Progreso {
    public static void main(String[] arg) throws IOException
    {
        File file = new File("/home/usuario/DAM2/PSP/ut02Java/Ejercicio1/ifconfig.txt");
        file.createNewFile();
        FileWriter writer = new FileWriter(file);
        List<String> cmdList = new ArrayList<String>();
        String line;

        cmdList.add("ifconfig");
        cmdList.add("-a");
        ProcessBuilder  processBuilder = new ProcessBuilder(cmdList);
        Process process = processBuilder.start();
        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

        
        while ((line = reader.readLine()) != null) {
            writer.write(line + "\n");
        }
        writer.close();

        try {
            process.waitFor();
            System.out.println("Proceso terminado!");
        } catch (Exception e) {
            e.getMessage();
        }
    }
}