package ut02Java.Threads.Ejercicio6;

public class pistora implements Runnable{ 
    corredo c;
    public pistora(corredo c){
        this.c = c;
    }
    @Override
    public void run() {
        synchronized(c){
            c.setStart(true);
            c.correr();
            c.notifyAll();
        }
    }


}
