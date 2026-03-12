import java.util.HashSet;
import java.util.Set;

public class sets {
    public static void main(String[] args) {
        @SuppressWarnings("Convert2Diamond")
        Set<Integer> t = new HashSet<Integer>();
        //set consist of only unique elements if we try to add same elements, it will consider only single unique element

        t.add(5);
        t.add(5);
        t.add(8);
        t.add(6);

        System.out.println(t);
        // [5, 6, 8]  : arrange the elements in acsending order

        System.out.println(t.contains(8));  //true
        System.out.println(t.contains(1));  //false

    }
}


//to comapare

//setList