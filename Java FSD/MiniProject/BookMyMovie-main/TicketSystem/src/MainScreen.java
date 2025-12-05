import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainScreen extends JFrame {

    public MainScreen() {
        setTitle("Movie Booking System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(500, 300));

        JButton bookTicketsButton = new JButton("Book Tickets");
        bookTicketsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                BookTicketsScreen book = new BookTicketsScreen();
                book.setVisible(true);
                setVisible(false);
            }
        });

        JButton adminModeButton = new JButton("Admin Mode");
        adminModeButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                AdminScreen adminScreen = new AdminScreen();
                setVisible(false);
            }
        });

        JPanel buttonPanel = new JPanel(new GridLayout(2, 1, 10, 10));
        buttonPanel.add(bookTicketsButton);
        buttonPanel.add(adminModeButton);
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(50, 50, 50, 50));

        add(buttonPanel);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
