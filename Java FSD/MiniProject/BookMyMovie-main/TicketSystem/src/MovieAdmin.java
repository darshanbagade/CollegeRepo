import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class MovieAdmin extends JFrame implements ActionListener {

    private JPanel panel;
    private JLabel movieLabel;
    private JTextField movieNameField;
    private JLabel priceLabel;
    private JTextField priceField;
    private JLabel timingLabel;
    private JTextField timingField;
    private JLabel languageLabel;
    private JTextField languageField;
    private JButton updateButton;
    private JButton resetButton;
    private JButton backButton;
    private int movieId;
    private Movie movie;

    DBConnection connect;

    {
        try {
            connect = new DBConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public MovieAdmin(Movie movie, int movieId) {
        this.movie = movie;
        this.movieId = movieId;

        setTitle("Admin Mode");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panel = new JPanel();
        panel.setLayout(null);

        movieLabel = new JLabel("Movie Name:");
        movieLabel.setBounds(50, 50, 100, 25);
        panel.add(movieLabel);

        movieNameField = new JTextField(movie.getMovieName());
        movieNameField.setBounds(150, 50, 200, 25);
        panel.add(movieNameField);

        priceLabel = new JLabel("Ticket Price:");
        priceLabel.setBounds(50, 100, 100, 25);
        panel.add(priceLabel);

        priceField = new JTextField(String.valueOf(movie.getTicketPrice()));
        priceField.setBounds(150, 100, 200, 25);
        panel.add(priceField);

        timingLabel = new JLabel("Timing:");
        timingLabel.setBounds(50, 150, 100, 25);
        panel.add(timingLabel);

        timingField = new JTextField(movie.getTiming());
        timingField.setBounds(150, 150, 200, 25);
        panel.add(timingField);

        languageLabel = new JLabel("Language:");
        languageLabel.setBounds(50, 200, 100, 25);
        panel.add(languageLabel);

        languageField = new JTextField(movie.getLanguage());
        languageField.setBounds(150, 200, 200, 25);
        panel.add(languageField);

        updateButton = new JButton("Update");
        updateButton.setBounds(50, 250, 100, 25);
        updateButton.addActionListener(this);
        panel.add(updateButton);

        resetButton = new JButton("Reset Seats");
        resetButton.setBounds(200, 250, 200, 25);
        resetButton.addActionListener(this);
        panel.add(resetButton);

        backButton = new JButton("Back");
        backButton.setBounds(50, 350, 100, 25);
        backButton.addActionListener(this);
        panel.add(backButton);


        setContentPane(panel);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == updateButton) {

            movie.setMovieName(movieNameField.getText());
            movie.setTicketPrice(Integer.parseInt(priceField.getText()));
            movie.setTiming(timingField.getText());
            movie.setLanguage(languageField.getText());

            connect.setMovieDetails(movie, movieId);

            JOptionPane.showMessageDialog(panel, "Movie details updated successfully!");
        }
        else if (e.getSource() == resetButton) {
            connect.resetSeats(movieId);
            JOptionPane.showMessageDialog(panel, "Seats reset successfully!");
        }
        else if (e.getSource() == backButton) {
            setVisible(false);
            MainScreen screen = new MainScreen();
            screen.setVisible(true);
        }
    }
}
