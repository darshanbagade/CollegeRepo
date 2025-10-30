class Employee {
    String name;
    int employeeId;

    Employee(String name, int employeeId) {
        this.name = name;
        this.employeeId = employeeId;
    }

    void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + employeeId);
    }
}

class FullTimeEmployee extends Employee {
    double salary;

    FullTimeEmployee(String name, int employeeId, double salary) {
        super(name, employeeId);
        this.salary = salary;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Type: Full-Time Employee");
        System.out.println("Salary: ₹" + salary);
        System.out.println("-----------------------------");
    }
}

class PartTimeEmployee extends Employee {
    double hourlyRate;
    int hoursWorked;

    PartTimeEmployee(String name, int employeeId, double hourlyRate, int hoursWorked) {
        super(name, employeeId);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Type: Part-Time Employee");
        System.out.println("Hourly Rate: ₹" + hourlyRate);
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Total Pay: ₹" + (hourlyRate * hoursWorked));
        System.out.println("-----------------------------");
    }
}

public class EmployeeManagement {
    public static void main(String[] args) {
        FullTimeEmployee e1 = new FullTimeEmployee("Alice", 101, 60000);
        PartTimeEmployee e2 = new PartTimeEmployee("Bob", 102, 500, 40);

        Employee[] employees = {e1, e2};

        System.out.println("=== Employee Details ===");
        for (Employee e : employees) {
            e.displayDetails();
        }
    }
}
