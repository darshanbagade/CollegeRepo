import java.sql.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

@SuppressWarnings("SpellCheckingInspection")
public class DBConnection {
    private static String url = "jdbc:mysql://localhost:3306/bookmymovie";
    private static String user = "root";
    private static String password = "password";

    private static Connection connection;

    static {
        try {
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public DBConnection() throws SQLException {
        System.out.println("Connected to the database!");
        createDatabase();
        createTables();
    }

    public void closeConnection() throws SQLException {
        connection.close();
        System.out.println("Disconnected from the database.");
    }

    public Movie getMovieDetails(int num) throws SQLException {
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery("SELECT * FROM movies WHERE id = " + num + ";");

        Movie movie = new Movie();

        if (resultSet.next()) {
            movie.setMovieName(resultSet.getString("movie_name"));
            movie.setTicketPrice(resultSet.getInt("ticket_price"));
            movie.setTiming(resultSet.getString("timing"));
            movie.setLanguage(resultSet.getString("mlanguage"));
        }

        resultSet.close();
        statement.close();
        return movie;
    }

    public void setMovieDetails(Movie movie, int id){
        Statement statement = null;
        try {
            statement = connection.createStatement();
            String query = "UPDATE movies" +
                    " SET " +
                    " movie_name = '" + movie.getMovieName() + "'," +
                    " ticket_price = " + movie.getTicketPrice() +"," +
                    " timing = '" + movie.getTiming()  + "'," +
                    " mlanguage = '" + movie.getLanguage() +
                    "' WHERE id = " + id + ";";
            int rowsUpdated = statement.executeUpdate(query);
            System.out.println(rowsUpdated + " rows updated.");

            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertSeats(){
        Statement statement = null;
        try {
            statement = connection.createStatement();

            for (int movieId = 1; movieId <= 3; movieId++) {
                for (int seatNumber = 1; seatNumber <= 20; seatNumber++) {
                    String query = "INSERT INTO seats (avail, seat_number, movie_id) VALUES (true, " + seatNumber + ", " + movieId + ")";
                    statement.executeUpdate(query);
                }
            }

            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public Set<Integer> getPrivateNonAvailable(int movieId){

        Set<Integer> set = new HashSet<>();
        Statement statement = null;

        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT seat_number FROM seats WHERE avail = 0 AND movie_id = " + movieId + ";");
            while (resultSet.next()) {
                set.add(resultSet.getInt("seat_number"));
            }
            resultSet.close();
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return set;
    }

    public void setPrivateNonAvailable(Set<Integer> privateNonAvailable, int movieId) {
        Statement statement;
        int rowsUpdated = 0;
        try {
            statement = connection.createStatement();
            for (int id : privateNonAvailable) {
                String query = "UPDATE seats " +
                        "SET " +
                        "avail = 0 " +
                        "WHERE movie_id = " + movieId + " AND seat_number = " + id + ";";
                rowsUpdated = statement.executeUpdate(query);
            }
            System.out.println(rowsUpdated + " rows updated.");
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void resetSeats(int movieId) {
        Statement statement;
        try {
            statement = connection.createStatement();
                String query = "UPDATE seats " +
                        "SET " +
                        "avail = 1 " +
                        "WHERE movie_id = " + movieId + ";";
                int rowsUpdated = statement.executeUpdate(query);
                System.out.println(rowsUpdated + " rows updated.");

            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void createDatabase() throws SQLException {
        Statement statement = connection.createStatement();
        statement.executeUpdate("CREATE DATABASE IF NOT EXISTS bookmymovie;");
        statement.executeUpdate("USE bookmymovie;");
        statement.close();
    }

    private void createTables() throws SQLException {
        Statement statement = connection.createStatement();

        statement.executeUpdate("CREATE TABLE IF NOT EXISTS movies (" +
                "  id INT AUTO_INCREMENT PRIMARY KEY," +
                "  movie_name VARCHAR(255) NOT NULL," +
                "  ticket_price INT NOT NULL," +
                "  timing VARCHAR(18) NOT NULL," +
                "  mlanguage VARCHAR(32) NOT NULL" +
                ");");

        statement.executeUpdate("CREATE TABLE IF NOT EXISTS seats (" +
                "  id INT AUTO_INCREMENT PRIMARY KEY," +
                "  avail BOOLEAN," +
                "  seat_number INT NOT NULL," +
                "  movie_id INT NOT NULL," +
                "  FOREIGN KEY (movie_id) REFERENCES movies(id)" +
                ");");

        statement.executeUpdate("CREATE TABLE IF NOT EXISTS bookings (" +
                "  id INT AUTO_INCREMENT PRIMARY KEY," +
                "  movie_id INT NOT NULL, billDate DATE," +
                "  billAmount int," +
                "  seat_id INT NOT NULL," +
                "  FOREIGN KEY (movie_id) REFERENCES movies(id)," +
                "  FOREIGN KEY (seat_id) REFERENCES seats(id)" +
                ");");

        statement.close();
    }

    private void initializeSeats() throws SQLException {
        Statement statement = connection.createStatement();

        statement.executeUpdate("INSERT INTO movies" +
                "VALUES" +
                "    (1, __, 0, __, __)," +
                "    (2, __, 0, __, __)," +
                "    (3, __, 0, __, __);");

        statement.executeUpdate("UPDATE seats\n" +
                "\tSET\n" +
                "    avail = 1\n" +
                "    WHERE movie_id = 1 OR movie_id = 2 OR movie_id = 3;");

        statement.close();
    }

    public void addBill(HashMap<Integer, Integer> seatPriceMap, int movieId, int totalBill) {
        Statement statement;
        int rowsUpdated = 0;
        try {
            statement = connection.createStatement();
                String query = "INSERT INTO bookings (movie_id, billDate, billAmount) VALUES( " + movieId + ", CURDATE(), " + totalBill + ");";
                rowsUpdated = statement.executeUpdate(query);
            System.out.println(rowsUpdated + " rows updated.");
            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static Connection getConnection() {
        return connection;
    }
}
