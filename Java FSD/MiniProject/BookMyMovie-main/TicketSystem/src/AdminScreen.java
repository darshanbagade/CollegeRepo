import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class AdminScreen implements ActionListener {
    private JFrame frame;

    private Movie movieOne = new Movie();
    private Movie movieTwo = new Movie();
    private Movie movieThree = new Movie();

    private JButton movie1Button;
    private JButton movie2Button;
    private JButton movie3Button;
    private JButton showBills;

    private DBConnection connect;

    {
        try {
            connect = new DBConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public AdminScreen() {
        frame = new JFrame("Admin Mode");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);

        JPanel panel = new JPanel(new GridLayout(4, 1, 10, 10));

        movie1Button = movieOne.getMovieButton();
        movie2Button = movieTwo.getMovieButton();
        movie3Button = movieThree.getMovieButton();
        showBills = new JButton("Show Bills");

        movie1Button.setText("Movie 1");
        movie2Button.setText("Movie 2");
        movie3Button.setText("Movie 3");

        movie1Button.addActionListener(this);
        movie2Button.addActionListener(this);
        movie3Button.addActionListener(this);
        showBills.addActionListener(this);

        panel.add(movie1Button);
        panel.add(movie2Button);
        panel.add(movie3Button);
        panel.add(showBills);
        panel.setBorder(BorderFactory.createEmptyBorder(50, 50, 50, 50));
        frame.add(panel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (movie1Button.equals(e.getSource())) {
            try {
                movieOne = connect.getMovieDetails(1);
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            MovieAdmin movies = new MovieAdmin(movieOne, 1);
            movies.setVisible(true);
            frame.setVisible(false);
        }
        else if (movie2Button.equals(e.getSource())) {
            try {
                movieTwo = connect.getMovieDetails(2);
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            MovieAdmin movies = new MovieAdmin(movieTwo, 2);
            movies.setVisible(true);
            frame.setVisible(false);
        }
        else if (movie3Button.equals(e.getSource())) {
            try {
                movieThree = connect.getMovieDetails(3);
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
            MovieAdmin movies = new MovieAdmin(movieThree, 3);
            movies.setVisible(true);
            frame.setVisible(false);
        }

        if(showBills.equals(e.getSource())) {
            ShowBookings showBookings = new ShowBookings();
            showBookings.setVisible(true);
        }
    }

}