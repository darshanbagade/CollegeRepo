import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class BillScreen extends JFrame {

    private Movie movie;
    private Set<Integer> bookedSeats;
    private HashMap<Integer, Integer> seatPriceMap;
    private DBConnection connection;

    {
        try {
            connection = new DBConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }


    public BillScreen(Set<Integer> bookedSeats, Movie movie, HashMap<Integer, Integer> seatPriceMap, int movieId) {
        this.movie = movie;
        this.seatPriceMap = seatPriceMap;
        this.bookedSeats = bookedSeats;

        setTitle("Booking Confirmation");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setPreferredSize(new Dimension(400, 400));


        int totalBill = calculateTotalBill(seatPriceMap);


        JLabel movieLabel = new JLabel("Movie: " + movie.getMovieName());
        movieLabel.setFont(new Font("Arial", Font.BOLD, 18));
        movieLabel.setHorizontalAlignment(SwingConstants.CENTER);


        JLabel seatsLabel = new JLabel("Number of Seats: " + seatPriceMap.size());
        seatsLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        seatsLabel.setHorizontalAlignment(SwingConstants.CENTER);

        StringBuilder seatDetails = new StringBuilder();
        seatDetails.append("<html><body><b>Seat Details:</b><br>");
        for (Map.Entry<Integer, Integer> entry : seatPriceMap.entrySet()) {
            int seatNumber = entry.getKey();
            int seatPrice = entry.getValue();
            seatDetails.append("Seat ").append(seatNumber).append(": Rs").append(seatPrice).append("<br>");
        }
        seatDetails.append("</body></html>");
        JLabel seatDetailsLabel = new JLabel(seatDetails.toString());
        seatDetailsLabel.setFont(new Font("Arial", Font.PLAIN, 16));
        seatDetailsLabel.setHorizontalAlignment(SwingConstants.CENTER);

        JLabel totalBillLabel = new JLabel("Total Bill: Rs" + totalBill);
        totalBillLabel.setFont(new Font("Arial", Font.BOLD, 18));
        totalBillLabel.setHorizontalAlignment(SwingConstants.CENTER);


        JButton confirmButton = new JButton("Confirm Booking");
        confirmButton.addActionListener(e -> {
            connection.setPrivateNonAvailable(bookedSeats, movieId);
            connection.addBill(seatPriceMap, movieId, totalBill);
            System.out.println("Application Exited Successfully");
            System.exit(0);
        });


        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(6, 1, 10, 10));
        panel.add(movieLabel);
        panel.add(seatsLabel);
        panel.add(seatDetailsLabel);
        panel.add(totalBillLabel);
        panel.add(confirmButton);

        add(panel);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private int calculateTotalBill(HashMap<Integer, Integer> seatPriceMap) {
        int totalBill = 0;
        for (Map.Entry<Integer, Integer> entry : seatPriceMap.entrySet()) {
            int seatPrice = entry.getValue();
            totalBill += seatPrice;
        }
        return totalBill;
    }
}