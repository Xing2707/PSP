package Examen.Ejercicio4;

import ut02Java.Ejemplos.EjemploThreaded.principal;

public class cohetes implements Runnable{

    private int km_corrido;
    private int km_avanza;
    private static int cont_falla;
    private static int cont_llega;
    private final int MAX_TIME = 1000;
    private final int MIN_TIME = 500;
    private final int POSIBILIDAD_FALLO = 1;
    private final double FALLAR = 0.1;
    private Object propulsores;

    public cohetes(int km_avanza,Object propulsores){
        this.km_corrido = 408;
        this.km_avanza = km_avanza;
        this.propulsores = propulsores;
        this.cont_falla = 0;
        this.cont_llega = 0;
    }
    
    public static int getCont_falla() {
        return cont_falla;
    }

    public static int getCont_llega() {
        return cont_llega;
    }

    @Override
    public void run() {
        int num_rand =(int)((Math.random() * MAX_TIME) + MIN_TIME);
        try {
            Thread.sleep(num_rand);
            while (km_corrido < index.TOTAL_CORRIDO) {
                synchronized(propulsores){
                    double fallo = Math.random() * POSIBILIDAD_FALLO;
                    if(fallo < FALLAR){
                        cont_falla ++;
                        wait();
                    }else{
                        km_corrido += km_avanza;
                        if(km_corrido == index.TOTAL_CORRIDO){
                            cont_llega ++;
                        }
                    }
                }
            }
        } catch (InterruptedException e) {
        }
        
    }

}
