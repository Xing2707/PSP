package Ejercicio7;

public interface interfaceAscensor {
    public void config(int id,String ip, int port);
    public void run();
    public void subir();
    public void bajar();
    public String getplanta();
    public String toProtocolo();
    public interfaceAscensor fromProtocolo(String data);
}
