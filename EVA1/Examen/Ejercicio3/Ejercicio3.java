package Examen.Ejercicio3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Scanner;

public class Ejercicio3 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String cadena1 = sc.nextLine();
        String cadena2 = sc.nextLine();

        ArrayList<String> cmd = new ArrayList<String>();
        cmd.add("md5sum");
        cmd.add(cadena2);

        ProcessBuilder builder = new ProcessBuilder(cmd);
        Process process = builder.start();

        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        
        
    }
}
