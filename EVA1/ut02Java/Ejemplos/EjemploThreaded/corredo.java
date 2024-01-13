package ut02Java.Ejemplos.EjemploThreaded;

public class corredo implements Runnable{
    private static final long DESCANSO = 500;
    private static final double INTERVALO_KM = 10;
    int km_corrido;
    int distancia;
    int docsal;

    public corredo(int docsal,int distancia) {
        this.docsal = docsal;
        this.distancia = distancia;
        this.km_corrido = 0;
    }

    @Override
    public void run() {
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
        System.out.println(String.format("Soy docsal %d he terminado la carrera",docsal));
    }
    
}
