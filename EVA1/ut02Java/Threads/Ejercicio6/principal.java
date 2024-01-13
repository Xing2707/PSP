package ut02Java.Threads.Ejercicio6;

public class principal{
    private static final int TOTAL_CARRERA = 100;
    private static final int NUM_DOCSAL = 1000;
    private static final int TWO = 2;

    public static void main(String[] args) throws InterruptedException{
        corredo c1 = new corredo((int)(Math.random() * NUM_DOCSAL + NUM_DOCSAL/TWO) , (int)(Math.random() * TOTAL_CARRERA + TOTAL_CARRERA/TWO));
        corredo c2 = new corredo((int)(Math.random() * NUM_DOCSAL + NUM_DOCSAL/TWO) , (int)(Math.random() * TOTAL_CARRERA + TOTAL_CARRERA/TWO));
        corredo c3 = new corredo((int)(Math.random() * NUM_DOCSAL + NUM_DOCSAL/TWO) , (int)(Math.random() * TOTAL_CARRERA + TOTAL_CARRERA/TWO));
        Thread t1 = new Thread(new salida(c1));
        Thread t2 = new Thread(new salida(c2));
        Thread t3 = new Thread(new salida(c3));
        Thread t4 = new Thread(new pistora(c1));
        Thread t5 = new Thread(new pistora(c2));
        Thread t6 = new Thread(new pistora(c3));
        t1.start();
        t2.start();
        t3.start();

        t4.start();
        t5.start();
        t6.start();
    }
}
