// Program 2 - Determine number of bytes written

import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Pr2_DataOutputExample {
    public static void main(String[] args) {
        try {
            DataOutputStream dos = new DataOutputStream(new FileOutputStream("data.txt"));
            dos.writeUTF("Java File Handling Example");
            System.out.println("Bytes written: " + dos.size());
            dos.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
