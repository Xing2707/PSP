package ut02Java.contador;

public class contador implements Runnable{
    
    private static final long TIEMPO = 100;
    private int contador;
    private boolean seguir;
    public contador(){
        contador = 0;
        seguir = true;
    }
    
    public synchronized void parar(){
        seguir = false;
    }

    @Override
    public void run() {
        while (seguir) {
            try {
                Thread.sleep(TIEMPO);
                contador ++;
            } catch (InterruptedException e) {
                System.out.println(String.format("ha contado: %d", contador));
                contador = 0;
            }
        }
    }
}
