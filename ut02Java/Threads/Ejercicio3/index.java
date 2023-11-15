package ut02Java.Threads.Ejercicio3;

public class index {
    public static void main(String[] args) {
     
        Animales a1 = new Animales("Jirafa", "cantar cancion \nComo veia a otra jirafa,se fue a llamar para cantar junto ", 10);
        Animales a2 = new Animales("Cerdo", "jugar charco \nComo veia a otra cerdo,se fue a llamar para jugar junto", 15);
        Animales a3 = new Animales("Pajaro", "comer cusano \nComo veia a otra pajaro,se fue a llamar para comer junto", 20);

        Thread t1 = new Thread(a1);
        Thread t2 = new Thread(a2);
        Thread t3 = new Thread(a3);

        t1.setPriority(Thread.MIN_PRIORITY);
        t2.setPriority(Thread.MAX_PRIORITY);
        t3.setPriority(Thread.NORM_PRIORITY);
        
        t1.start();
        t2.start();
        t3.start();
    }
}
