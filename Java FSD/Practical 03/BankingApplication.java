// Program for PS1 - Simple Banking Application

import java.util.HashMap;

class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(String message) {
        super(message);
    }
}

class AccountNotFoundException extends Exception {
    public AccountNotFoundException(String message) {
        super(message);
    }
}

public class BankingApplication {
    private HashMap<Integer, Double> accounts = new HashMap<>();

    public void addAccount(int accountNumber, double balance) {
        accounts.put(accountNumber, balance);
    }

    public void deposit(int accountNumber, double amount) throws AccountNotFoundException {
        if (!accounts.containsKey(accountNumber)) {
            throw new AccountNotFoundException("Account not found: " + accountNumber);
        }
        accounts.put(accountNumber, accounts.get(accountNumber) + amount);
        System.out.println("Deposited ₹" + amount + " to account " + accountNumber);
    }

    public void withdraw(int accountNumber, double amount)
            throws AccountNotFoundException, InsufficientBalanceException {
        if (!accounts.containsKey(accountNumber)) {
            throw new AccountNotFoundException("Account not found: " + accountNumber);
        }
        double balance = accounts.get(accountNumber);
        if (amount > balance) {
            throw new InsufficientBalanceException("Insufficient balance for account " + accountNumber);
        }
        accounts.put(accountNumber, balance - amount);
        System.out.println("Withdrawn ₹" + amount + " from account " + accountNumber);
    }

    public void displayAllAccounts() {
        System.out.println("\n--- Account Details ---");
        for (var entry : accounts.entrySet()) {
            System.out.println("Account No: " + entry.getKey() + " | Balance: ₹" + entry.getValue());
        }
    }

    public static void main(String[] args) {
        BankingApplication bank = new BankingApplication();
        bank.addAccount(101, 5000);
        bank.addAccount(102, 10000);

        try {
            bank.deposit(101, 2000);
            bank.withdraw(102, 3000);
            bank.withdraw(101, 8000); // will throw exception
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        bank.displayAllAccounts();
    }
}
