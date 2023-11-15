package ut02Java.Ejemplos.EjemploThreaded;

public class principal{
    private static final int TOTAL_CARRERA = 100;
    private static final int NUM_DOCSAL = 1000;
    private static final int FIRST = 0;
    private static final int NUM_CORREDO = 10;

    public static void main(String[] args) throws InterruptedException{
        Thread[] corredores = new Thread[NUM_CORREDO];

        for(int i = 0; i < NUM_CORREDO; i++){
            corredores[i] = new Thread(
                new corredo((int)(Math.random() * NUM_DOCSAL) + NUM_DOCSAL,(int)(Math.random() * TOTAL_CARRERA/2) + (TOTAL_CARRERA))
            );
        }

        System.out.println("La carrera se va envezar.");

        for(int y = 0; y < NUM_CORREDO; y++){
            corredores[y].start();
        }

        for(int h = 0; h < NUM_CORREDO; h++){
            corredores[h].join();
        }
        
        System.out.println("La carrera se ha terminado");

        //Thread con argumentos.
        // Thread t1 = null;
        // corredo c1 =null;

        // System.out.println("La carrera se va envezar.");

        // for(int i = 0; i < Integer.parseInt(args[FIRST]); i++){
        //     c1 = new corredo((int)(Math.random() * NUM_DOCSAL) + NUM_DOCSAL,(int)(Math.random() * TOTAL_CARRERA/2) + (TOTAL_CARRERA));
        //     t1 = new Thread(c1);    
        //     t1.start();
        // }

        // t1.join();
        // System.out.println("La carrera se ha terminado");
        
        // corredo c1 = new corredo(1101, TOTAL_CARRERA);
        // corredo c2 = new corredo(9998,TOTAL_CARRERA);
        // Thread t1 = new Thread(c1);
        // Thread t2 = new Thread(c2);

        // System.out.println("La carrera se va envezar.");
        // t1.start();
        // t2.start();

        // t1.join();
        // t2.join();

        // System.out.println("La carrera se ha terminado");
    }

}
