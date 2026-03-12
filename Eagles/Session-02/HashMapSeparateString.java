import java.util.HashMap;
import java.util.Map;

public class HashMapSeparateString {
    public static void main(String[] args) {
        Map<Character, Integer> m = new HashMap<>();
        String str = "I am learning Java";

        for (char x : str.toCharArray()) {
            if (m.containsKey(x)) {
                int old = m.get(x);
                m.put(x, old + 1); 
            } else {
                m.put(x, 1); 
            }
        }
        System.out.println(m);
    }
}
