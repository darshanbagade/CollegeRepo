import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class BookTicketsScreen extends JFrame {

    private Movie[] movies;

    public BookTicketsScreen() {
        setTitle("Book Tickets");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(500, 300));

        try {
            // Fetch details of all movies from the database
            DBConnection movieDetails = new DBConnection();
            movies = new Movie[]{
                    movieDetails.getMovieDetails(1),
                    movieDetails.getMovieDetails(2),
                    movieDetails.getMovieDetails(3)
            };

            // Create a panel to show details and buttons for all movies
            JPanel moviePanel = new JPanel(new GridLayout(3, 1, 10, 10));
            for (int i = 0; i < movies.length; i++) {
                JPanel panel = new JPanel(new GridLayout(4, 1));
                JLabel nameLabel = new JLabel("Name: " + movies[i].getMovieName());
                JLabel timingLabel = new JLabel("Timing: " + movies[i].getTiming());
                JLabel priceLabel = new JLabel("Price: Rs" + movies[i].getTicketPrice());
                JLabel languageLabel = new JLabel("Language: " + movies[i].getLanguage());
                JButton selectMovieButton = new JButton("Select Movie");
                int movieId = i + 1; // Assuming movie IDs start from 1
                selectMovieButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        SeatSelector seatSelectorScreen = new SeatSelector(movies[movieId - 1], movieId);
                        setVisible(false);
                    }
                });
                panel.add(nameLabel);
                panel.add(timingLabel);
                panel.add(priceLabel);
                panel.add(languageLabel);
                panel.add(selectMovieButton);
                panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
                moviePanel.add(panel);
            }

            // Add the movie panel to the main frame
            add(moviePanel, BorderLayout.CENTER);

        } catch (SQLException ex) {
            // Handle any SQL exceptions that occur while fetching movie details
            ex.printStackTrace();
            JOptionPane.showMessageDialog(null, "Failed to fetch movie details from database.", "Error", JOptionPane.ERROR_MESSAGE);
        }

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

}
