package ut02Java.Threads.Ejercicio1;

public class index {
    public static void main(String[] args) throws InterruptedException{
        Runnable runnable = ()->{
            System.out.println("Hola mundo");
        };
        
        runamble1 r1 = new runamble1();

        Thread1 t1 = new Thread1();
        Thread thread = new Thread(()->{
            System.out.println("Hola Mundo");
        });

        r1.run();
        runnable.run();
        t1.start();
        thread.start();
    }
}
