package ut02Java.Threads.Ejercicio4;

public class contador{
    public int count;
    
    public contador(int c){
        this.count = c;
    }
    
    @Override
    public String toString() {
        return String.valueOf(count);
    }
}
