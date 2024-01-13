package ut02Java.Threads.Ejercicio4;

public class increment implements Runnable{

    contador count;

    public increment(contador c){
        this.count = c;
    }
    @Override
    public void run() {
        synchronized(count){
            for(int i = 0; i < index.MAX_NUM; i++){
                count.count += 1;
            }
        }
    }

    
}
