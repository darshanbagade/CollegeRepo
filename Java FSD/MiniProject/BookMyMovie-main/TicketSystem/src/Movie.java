import javax.swing.*;

public class Movie {
    private JButton movieButton = new JButton();
    private String movieName;
    private int ticketPrice;
    private String timing;
    private String language;

    public JButton getMovieButton() {
        return movieButton;
    }

    public void setMovieButton(JButton movieButton) {
        this.movieButton = movieButton;
    }

    public String getMovieName() {
        return movieName;
    }

    public void setMovieName(String movieName) {
        this.movieName = movieName;
    }

    public int getTicketPrice() {
        return ticketPrice;
    }

    public void setTicketPrice(int ticketPrice) {
        this.ticketPrice = ticketPrice;
    }

    public String getTiming() {
        return timing;
    }

    public void setTiming(String timing) {
        this.timing = timing;
    }

    public String getLanguage() {
        return language;
    }

    public void setLanguage(String language) {
        this.language = language;
    }
}
