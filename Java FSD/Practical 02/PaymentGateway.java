// Program for PS2 - Payment Gateway System

abstract class PaymentMethod {
    public abstract void processPayment(double amount);
}

class CreditCardPayment extends PaymentMethod {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing credit card payment of ₹" + amount);
        System.out.println("Credit card payment successful.");
        System.out.println("---------------------------");
    }
}

class DebitCardPayment extends PaymentMethod {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing debit card payment of ₹" + amount);
        System.out.println("Debit card payment successful.");
        System.out.println("---------------------------");
    }
}

class DigitalWalletPayment extends PaymentMethod {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing digital wallet payment of ₹" + amount);
        System.out.println("Digital wallet payment successful.");
        System.out.println("---------------------------");
    }
}

public class PaymentGateway {
    public static void makePayment(PaymentMethod payment, double amount) {
        payment.processPayment(amount);
    }

    public static void main(String[] args) {
        PaymentMethod credit = new CreditCardPayment();
        PaymentMethod debit = new DebitCardPayment();
        PaymentMethod wallet = new DigitalWalletPayment();

        makePayment(credit, 2500);
        makePayment(debit, 1800);
        makePayment(wallet, 500);
    }
}
