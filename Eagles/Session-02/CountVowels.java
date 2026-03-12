import java.util.HashMap;
import java.util.Map;

public class CountVowels {
    
        public static void main(String[] args) {
            Map<Character, Integer> m = new HashMap<>();
            String str = "I am learning Java";
    
            for (char x : str.toCharArray()) {

               if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || 
               x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){ 
                    if (m.containsKey(x)) {
                    
                            int old = m.get(x);
                            m.put(x, old + 1);
                    } else {
                        m.put(x, 1); 
                    }
                }
            }
            System.out.println(m);
        }   
}
