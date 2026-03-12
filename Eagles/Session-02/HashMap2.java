import java.util.Map;
import java.util.HashMap;
public class HashMap2 {
    @SuppressWarnings("unchecked")
    public static void main(String[] args){
            Map m = (Map) new HashMap();
            m.put("User","Darshan");
            m.put("Email", "darshanbagade123@ycce.in");
            m.forEach((k, v) -> (System.out.println(k + v)));
            
    }
}
