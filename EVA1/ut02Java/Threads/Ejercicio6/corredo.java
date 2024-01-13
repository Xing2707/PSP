package ut02Java.Threads.Ejercicio6;

public class corredo {
    private static final long DESCANSO = 500;
    private static final double INTERVALO_KM = 10;
    private int km_corrido;
    private int distancia;
    private int docsal;
    public boolean start;

    public corredo(int docsal,int distancia) {
        this.docsal = docsal;
        this.distancia = distancia;
        this.km_corrido = 0;
    }

    public boolean isStart() {
        return start;
    }

    public void setStart(boolean start) {
        this.start = start;
    }

    public void correr() {
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

        System.out.println(String.format("Soy docsal %d he terminado la carrera he tardado %d milisecundo",docsal,(endTime - startTime)));
    }
}
