
import java.util.Scanner;

public class BMI {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter weight in pounds: ");
        double pounds = sc.nextDouble();
        System.out.print("Enter height in inches: ");
        double inches = sc.nextDouble();

        double weight = pounds * 0.45359237;
        double height = inches * 0.0254;
        double bmi = weight / (height * height);

        System.out.printf("Your BMI is: %.2f\n", bmi);

        if (bmi < 18.5) {
            System.out.println("Interpretation: Underweight");
        } else if (bmi < 25.0) {
            System.out.println("Interpretation: Normal");
        } else if (bmi < 30.0) {
            System.out.println("Interpretation: Overweight");
        } else {
            System.out.println("Interpretation: Obese");
        }
    }
}
