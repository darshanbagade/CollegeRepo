
import java.util.Scanner;
public class strings {
    public static void main(String[] args) {
        @SuppressWarnings("resource")
        String[] names = new String[5];
        Scanner sc = new Scanner(System.in);

        for(int i=0; i<names.length; i++){
            System.out.print("Input " +(1+i)+ " :" );
            String input = sc.nextLine();
            names[i] = input ;
        }
        System.out.println("Names : ");
        for(String element :names){
            System.out.println(element);
        }
        sc.close();
    }
}
