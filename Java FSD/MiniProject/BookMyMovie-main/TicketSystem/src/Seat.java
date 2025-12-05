import javax.swing.*;

public class Seat {
    private int seatNum;
    private boolean availability;
    private int price;
    private JButton seatButton = new JButton();

    public void setSeatButton(JButton seatButton) {
        this.seatButton = seatButton;
    }

    public JButton getSeatButton() {
        return seatButton;
    }

    public int getSeatNum() {
        return seatNum;
    }

    public boolean isAvailability() {
        return availability;
    }

    public int getPrice() {
        return price;
    }

    public void setSeatNum(int seatNum) {
        this.seatNum = seatNum;
    }

    public void setAvailability(boolean availability) {
        this.availability = availability;
    }

    public void setPrice(int price) {
        this.price = price;
    }
}
