import java.util.Scanner;
public class loops{
    public static void main(String[] args){
        @SuppressWarnings("resource")
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number :");
        int num = input.nextInt();
        int flag = 0 ;
        int i=2;
        if(num==0 || num==1){
            flag= 1;
        }

        while(i<num){
            if(num%i == 0 ){
                flag = 1;
                break;
            }
            i++;
        }
        if(flag == 1){
            System.out.println(num + " is not prime");
        }
        else{
            System.out.println(num + " is prime");
        } 

    }
}