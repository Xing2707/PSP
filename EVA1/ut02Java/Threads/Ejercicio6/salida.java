package ut02Java.Threads.Ejercicio6;

public class salida implements Runnable {
    corredo c;
    public salida(corredo c){
        this.c = c;
    }

    @Override
    public void run() {
        synchronized(c){
            while (!c.start) {
                
                try {
                    c.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            if(c.start){
                c.notify();
            }
        }
        
    }
}
