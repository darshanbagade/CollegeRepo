import java.util.Map;
// import java.util.HashMap;

public class HashMap{
    @SuppressWarnings("unchecked")
    public static void main(String[] args){
        @SuppressWarnings("rawtypes")
        Map m = (Map) new HashMap();
        m.put("User","Darshan");
        m.put("Email", "darshanbagade123@ycce.in");
        System.out.println(m);
    }
}