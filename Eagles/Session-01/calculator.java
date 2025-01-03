import java.util.Scanner;

public class calculator {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice;

        while(true) {
            System.out.println("Select option: ");
            System.out.println("1. Add");
            System.out.println("2. Subtract");
            System.out.println("3. Multiply");
            System.out.println("4. Divide");
            System.out.println("5. Exit");

            choice = input.nextInt();

            // Exit condition
            if (choice == 5) {
                input.close();
                System.out.println("Exiting program...");
                break;  // exit the loop
            }

           int num1;
           int num2;

            switch (choice) {
                case 1 -> {
                    System.out.println("Enter 1st number: ");
                    num1 = input.nextInt();
                    System.out.println("Enter 2nd number: ");
                    num2 = input.nextInt();
                    System.out.println("Sum is " + (num1 + num2));
                }
                case 2 -> {
                    System.out.println("Enter 1st number: ");
                    num1 = input.nextInt();
                    System.out.println("Enter 2nd number: ");
                    num2 = input.nextInt();
                    System.out.println("Subtraction is " + (num1 - num2));
                }
                case 3 -> {
                    System.out.println("Enter 1st number: ");
                    num1 = input.nextInt();
                    System.out.println("Enter 2nd number: ");
                    num2 = input.nextInt();
                    System.out.println("Multiplication is " + (num1 * num2));
                }
                case 4 -> {
                    System.out.println("Enter 1st number: ");
                    num1 = input.nextInt();
                    System.out.println("Enter 2nd number: ");
                    num2 = input.nextInt();
                    if (num2 == 0) {
                        System.out.println("Denominator cannot be zero.");
                    } else {
                        System.out.println("Division is " + (double) (num1/num2));
                    }
                }
                default -> System.out.println("Invalid input! Try again.");
            }
        }
    }
}
