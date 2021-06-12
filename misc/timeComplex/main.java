
import java.util.*;

class main{
    public static void main(String[] args){
        Map<Integer,String> mp = new HashMap<Integer,String>();

        mp.put(11,"abc");
        mp.put(13,"absc");
        mp.put(null,null);

        System.out.println(mp.size());

        System.out.println(mp);
    }
}