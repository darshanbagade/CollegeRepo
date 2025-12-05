import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class ShowBookings extends JFrame {

    private DBConnection connection;

    public ShowBookings() {
        try {
            connection = new DBConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        setTitle("Bookings");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setPreferredSize(new Dimension(600, 400));

        DefaultTableModel tableModel = new DefaultTableModel();
        JTable table = new JTable(tableModel);

        tableModel.addColumn("Booking ID");
        tableModel.addColumn("Movie ID");
        tableModel.addColumn("Bill Date");
        tableModel.addColumn("Bill Amount");

        try {
            Statement statement = connection.getConnection().createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT * FROM bookings");

            while (resultSet.next()) {
                int bookingId = resultSet.getInt("id");
                int movieId = resultSet.getInt("movie_id");
                String billDate = resultSet.getString("billDate");
                int billAmount = resultSet.getInt("billAmount");

                tableModel.addRow(new Object[]{bookingId, movieId, billDate, billAmount});
            }

            resultSet.close();
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

        JScrollPane scrollPane = new JScrollPane(table);
        getContentPane().add(scrollPane, BorderLayout.CENTER);

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
