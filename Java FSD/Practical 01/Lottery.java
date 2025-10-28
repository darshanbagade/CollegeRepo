import java.util.Scanner;
import java.util.Random;

public class Lottery {
    public static void main(String[] args) {
        Random rand = new Random();
        int lottery = rand.nextInt(90) + 10;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a two-digit number: ");
        int guess = sc.nextInt();

        int lotteryDigit1 = lottery / 10;
        int lotteryDigit2 = lottery % 10;
        int guessDigit1 = guess / 10;
        int guessDigit2 = guess % 10;

        if (guess == lottery) {
            System.out.println("Exact match: You win $10,000");
        } else if (guessDigit1 == lotteryDigit2 && guessDigit2 == lotteryDigit1) {
            System.out.println("Match all digits: You win $3,000");
        } else if (guessDigit1 == lotteryDigit1 || guessDigit1 == lotteryDigit2 ||
                guessDigit2 == lotteryDigit1 || guessDigit2 == lotteryDigit2) {
            System.out.println("Match one digit: You win $1,000");
        } else {
            System.out.println("Sorry, no match");
        }
        System.out.println("Lottery number was: " + lottery);
    }
}
