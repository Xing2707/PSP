package ut02Java.Threads.Ejercicio4;

public class index {
    public static final int MAX_NUM = 100000;
    private static final int ZERO = 0;

    public static void main(String[] args) {
        contador c = new contador(ZERO);
        increment i1 = new increment(c);
        decrement d1 = new decrement(c);
        
        Thread t1 = new Thread(i1);
        Thread t2 = new Thread(d1);
        
        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        System.out.println(String.format("El contador : %s", c));
    }
}
