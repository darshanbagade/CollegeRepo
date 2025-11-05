// Program 5 - Read CSV and display student name with total marks
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

class Student {
    int rollNo;
    String name;
    int maths;
    int physics;
    int chemistry;

    public Student(int rollNo, String name, int maths, int physics, int chemistry) {
        this.rollNo = rollNo;
        this.name = name;
        this.maths = maths;
        this.physics = physics;
        this.chemistry = chemistry;
    }

    public int totalMarks() {
        return maths + physics + chemistry;
    }
}

public class Pr5_StudentCSVReader {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("student.csv"))) {
            String line;
            br.readLine(); // Skip header line

            while ((line = br.readLine()) != null) {
                String[] data = line.split("\t");
                int rollNo = Integer.parseInt(data[0].trim());
                String name = data[1].trim();
                int maths = Integer.parseInt(data[5].trim());
                int physics = Integer.parseInt(data[6].trim());
                int chemistry = Integer.parseInt(data[7].trim());

                students.add(new Student(rollNo, name, maths, physics, chemistry));
            }

            System.out.println("--- Student Total Marks ---");
            for (Student s : students) {
                System.out.println("Name: " + s.name + " | Total Marks: " + s.totalMarks());
            }

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}
