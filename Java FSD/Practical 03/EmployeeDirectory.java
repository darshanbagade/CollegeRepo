// Program for PS2 - Employee Directory System

import java.util.ArrayList;

class DuplicateEmployeeException extends Exception {
    public DuplicateEmployeeException(String message) {
        super(message);
    }
}

class EmployeeNotFoundException extends Exception {
    public EmployeeNotFoundException(String message) {
        super(message);
    }
}

class Employee {
    int id;
    String name;
    String designation;

    public Employee(int id, String name, String designation) {
        this.id = id;
        this.name = name;
        this.designation = designation;
    }

    public void display() {
        System.out.println("ID: " + id + " | Name: " + name + " | Designation: " + designation);
    }
}

public class EmployeeDirectory {
    private ArrayList<Employee> employees = new ArrayList<>();

    public void addEmployee(Employee emp) throws DuplicateEmployeeException {
        for (Employee e : employees) {
            if (e.id == emp.id) {
                throw new DuplicateEmployeeException("Employee ID already exists: " + emp.id);
            }
        }
        employees.add(emp);
        System.out.println("Employee added successfully: " + emp.name);
    }

    public Employee searchEmployee(int id) throws EmployeeNotFoundException {
        for (Employee e : employees) {
            if (e.id == id) {
                return e;
            }
        }
        throw new EmployeeNotFoundException("Employee not found with ID: " + id);
    }

    public void displayAllEmployees() {
        System.out.println("\n--- Employee Directory ---");
        for (Employee e : employees) {
            e.display();
        }
    }

    public static void main(String[] args) {
        EmployeeDirectory directory = new EmployeeDirectory();

        try {
            directory.addEmployee(new Employee(1, "Alice", "Manager"));
            directory.addEmployee(new Employee(2, "Bob", "Developer"));
            directory.addEmployee(new Employee(1, "Charlie", "Tester")); // duplicate ID

        } catch (DuplicateEmployeeException e) {
            System.out.println("Error: " + e.getMessage());
        }

        try {
            Employee emp = directory.searchEmployee(2);
            System.out.println("\nSearch Result:");
            emp.display();

            directory.searchEmployee(5); // not found
        } catch (EmployeeNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }

        directory.displayAllEmployees();
    }
}
