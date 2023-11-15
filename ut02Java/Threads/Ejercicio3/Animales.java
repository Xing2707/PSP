package ut02Java.Threads.Ejercicio3;

public class Animales implements Runnable{
    private static final double NUM_MAX = 200000;
    private static final double NUM_MIN = 100000;
    private String animal;
    private String accion;
    private int veces;

    public Animales(String animal, String accion, int veces) {
        this.animal = animal;
        this.accion = accion;
        this.veces = veces;
    }
    
    @Override
    public void run() {
        for(int i = 0; i < veces; i++){
            System.out.println((i+1) +" " +  animal +" " + accion +"\n");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            int num = (int) (Math.random() * NUM_MAX + NUM_MIN);
            System.out.println("El numero generado" +num +(isPrime(num)?" es primo\n" : " no es primo\n"));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }   
    }

    private boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }
    
    
}
