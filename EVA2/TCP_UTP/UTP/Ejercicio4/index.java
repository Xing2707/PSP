package Ejercicio4;


public class index {
    private static final int PUERTO = 8080;
    public static void main(String[] args) {
        cliente c1 = new cliente(PUERTO,"localhost");
         cliente c2 = new cliente(PUERTO,"localhost");
        servidor s1 = new servidor(PUERTO);
        Thread t1 = new Thread(s1);
        Thread t2 = new Thread(c1);
        Thread t3 = new Thread(c2);
        t1.start();
        t2.start();
        t3.start();
        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }

    }
}
