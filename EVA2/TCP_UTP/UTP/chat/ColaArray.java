package chat;

import java.util.ArrayList;
import java.util.List;

public class ColaArray {
    public static List <String> list;

    public static void inicilizarCola(){
        if(list == null){
            list = new ArrayList<String>();
        }
    }

    public static void setMessage(String message){
        list.add(message);
    }

    public static List<String> getMessage(){
        List<String> newList = new ArrayList<>(list);
        list.clear();
        return newList;
    }
}
