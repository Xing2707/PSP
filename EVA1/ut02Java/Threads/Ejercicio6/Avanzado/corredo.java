package ut02Java.Threads.Ejercicio6.Avanzado;

public class corredo implements Runnable{
    private static final long DESCANSO = 500;
    private static final double INTERVALO_KM = 10;
    private Object pistora;
    int km_corrido;
    int distancia;
    int docsal;

    public corredo(int docsal,int distancia, Object pistora) {
        this.docsal = docsal;
        this.distancia = distancia;
        this.km_corrido = 0;
        this.pistora = pistora;
    }

    @Override
    public void run() {
        synchronized(pistora){
            try {
                pistora.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        long startTime = System.currentTimeMillis();
        System.out.println(String.format("Soy docsal %d voy a inicializar mi carrera",docsal));
        while (km_corrido < distancia) {
            try {
                Thread.sleep((long)(Math.random() * DESCANSO) + DESCANSO);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }

            km_corrido += Math.random() * INTERVALO_KM;
            System.out.println(String.format("DOCSAL %d %d/%d",docsal,km_corrido,distancia));
        }
        long endTime = System.currentTimeMillis();
        System.out.println(String.format("Soy docsal %d he terminado la carrera he tartado %d milisegundos",docsal,(endTime - startTime)));
    }
    
}
