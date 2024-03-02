package Miniproyecto;

public class Recibido implements Runnable{
    public interface MensajeRecibido{
        public void onMessage(String message);
    }

    private static final long DELAY = 100;

    private static final double MAX_NUM = 99;
    
    private MensajeRecibido manejadorInterno;
    
    public void setManejadorMensaje(MensajeRecibido manejador){
        manejadorInterno = manejador;    
    }

    @Override
    public void run() {
        while (true) {
            try{
                Thread.sleep(DELAY);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            int i = (int) ((Math.random() * MAX_NUM) +1);

            System.out.println(String.format("numero: %d",i));
            
            if(manejadorInterno != null) manejadorInterno.onMessage(String.valueOf(i));
            
        }
        
    }
    
}
