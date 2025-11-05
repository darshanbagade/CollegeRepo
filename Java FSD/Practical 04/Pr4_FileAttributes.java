// Program 4 - Get attributes of a file

import java.io.File;

public class Pr4_FileAttributes {
    public static void main(String[] args) {
        File file = new File("example.txt");

        if (file.exists()) {
            System.out.println("File Name: " + file.getName());
            System.out.println("Absolute Path: " + file.getAbsolutePath());
            System.out.println("Readable: " + file.canRead());
            System.out.println("Writable: " + file.canWrite());
            System.out.println("File Size (bytes): " + file.length());
            System.out.println("Last Modified: " + file.lastModified());
        } else {
            System.out.println("File not found.");
        }
    }
}
