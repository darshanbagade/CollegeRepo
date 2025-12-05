import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.List;
import java.util.*;

public class SeatSelector implements ActionListener {

    JFrame frame = new JFrame("Select Seats");

    GridLayout grid;
    Panel panel = new Panel();

    Set<Integer> privateNonAvailable;// = new HashSet<>();//Seats which are already booked
    HashMap<Integer, Integer> selectedSeats = new HashMap<>();//Seat Number, Ticket Price

    Seat seatOne = new Seat();
    Seat seatTwo = new Seat();
    Seat seatThree = new Seat();
    Seat seatFour = new Seat();
    Seat seatFive = new Seat();
    Seat seatSix = new Seat();
    Seat seatSeven = new Seat();
    Seat seatEight = new Seat();
    Seat seatNine = new Seat();
    Seat seatTen = new Seat();
    Seat seatEleven = new Seat();
    Seat seatTwelve = new Seat();
    Seat seatThirteen = new Seat();
    Seat seatFourteen = new Seat();
    Seat seatFifteen = new Seat();
    Seat seatSixteen = new Seat();
    Seat seatSeventeen = new Seat();
    Seat seatEighteen = new Seat();
    Seat seatNineteen = new Seat();
    Seat seatTwenty = new Seat();


    JButton b1 = seatOne.getSeatButton();
    JButton b2 = seatTwo.getSeatButton();
    JButton b3 = seatThree.getSeatButton();
    JButton b4 = seatFour.getSeatButton();
    JButton b5 = seatFive.getSeatButton();
    JButton b6 = seatSix.getSeatButton();
    JButton b7 = seatSeven.getSeatButton();
    JButton b8 = seatEight.getSeatButton();
    JButton b9 = seatNine.getSeatButton();
    JButton b10 = seatTen.getSeatButton();
    JButton b11 = seatEleven.getSeatButton();
    JButton b12 = seatTwelve.getSeatButton();
    JButton  b13 = seatThirteen.getSeatButton();
    JButton b14 = seatFourteen.getSeatButton();
    JButton b15 = seatFifteen.getSeatButton();
    JButton b16 = seatSixteen.getSeatButton();
    JButton b17 = seatSeventeen.getSeatButton();
    JButton b18 = seatEighteen.getSeatButton();
    JButton b19 = seatNineteen.getSeatButton();
    JButton b20 = seatTwenty.getSeatButton();
    JButton next = new JButton("        NEXT        ");

    List<Seat> allSeats = new ArrayList<>();

    private Movie movie;
    private int movieId;

    DBConnection connection;
    {
        try {
            connection = new DBConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    SeatSelector(Movie movie, int movieId){

        frame.setLayout(new FlowLayout());
        this.movie = movie;
        this.movieId = movieId;
        ////
        privateNonAvailable = connection.getPrivateNonAvailable(movieId);
        System.out.println(privateNonAvailable);

        next.addActionListener(this);
        allSeats.add(seatOne);
        allSeats.add(seatTwo);
        allSeats.add(seatThree);
        allSeats.add(seatFour);
        allSeats.add(seatFive);
        allSeats.add(seatSix);
        allSeats.add(seatSeven);
        allSeats.add(seatEight);
        allSeats.add(seatNine);
        allSeats.add(seatTen);
        allSeats.add(seatEleven);
        allSeats.add(seatTwelve);
        allSeats.add(seatThirteen);
        allSeats.add(seatFourteen);
        allSeats.add(seatFifteen);
        allSeats.add(seatSixteen);
        allSeats.add(seatSeventeen);
        allSeats.add(seatEighteen);
        allSeats.add(seatNineteen);
        allSeats.add(seatTwenty);

        addSeatNumbers();
        addListener();
        addButtonNumbers();
        setRedColor(allSeats);


        grid = new GridLayout(4, 4, 10, 20);
        panel.setLayout(grid);
        addButtonsToPanel();

        frame.add(panel);
        JLabel label = new JLabel("------------------------------------------Screen Here------------------------------------------");
        frame.add(label);
        frame.add(next);

        frame.getContentPane().setBackground(new Color(194, 197, 204));
        frame.setSize(500, 300);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (next.equals(e.getSource())) {
            nextOperation();
        }

        pressButton(b1, e);
        pressButton(b2, e);
        pressButton(b3, e);
        pressButton(b4, e);
        pressButton(b5, e);
        pressButton(b6, e);
        pressButton(b7, e);
        pressButton(b8, e);
        pressButton(b9, e);
        pressButton(b10, e);
        pressButton(b11, e);
        pressButton(b12, e);
        pressButton(b13, e);
        pressButton(b14, e);
        pressButton(b15, e);
        pressButton(b16, e);
        pressButton(b17, e);
        pressButton(b18, e);
        pressButton(b19, e);
        pressButton(b20, e);

    }

    private void pressButton(JButton button, ActionEvent f) {
        if (button.equals(f.getSource())) {
            int index = Integer.parseInt(button.getText());
            setGreenColor(allSeats.get(index-1));
        }
    }

    private void setRedColor(List<Seat> list){
        for(Seat seat : list){
            if(!seat.isAvailability())
                seat.getSeatButton().setBackground(new Color(240, 128, 128));
        }
    }

    private void setGreenColor(Seat seat){
        if(seat.isAvailability()){
            seat.getSeatButton().setBackground(new Color(0, 255, 127));
            seat.setAvailability(false);
            selectedSeats.put(seat.getSeatNum(), movie.getTicketPrice());
        }
    }

    private void addListener(){
        for(Seat seat : allSeats){
            seat.getSeatButton().addActionListener(this);
        }
    }
    private void addButtonNumbers(){
        int i =1;
        for(Seat seat : allSeats){
            seat.getSeatButton().setText(String.valueOf(i));
            i++;
        }
    }
    private void addSeatNumbers() {
        int i =1;
        for(Seat seat : allSeats){
            seat.setSeatNum(i);
            if(privateNonAvailable.contains(i)){
                seat.setAvailability(false);
            }
            else{
                seat.setAvailability(true);
            }
            i++;
        }
    }

    private void addButtonsToPanel(){
        for(Seat seat : allSeats){
            panel.add(seat.getSeatButton());
        }
    }

    private void nextOperation(){
        for(Seat seat : allSeats){
            if(!seat.isAvailability()){
                privateNonAvailable.add(seat.getSeatNum());
            }
        }
//        System.out.println(privateNonAvailable);
//        System.out.println(selectedSeats);

        BillScreen billScreen = new BillScreen(privateNonAvailable, movie, selectedSeats, movieId);
        billScreen.setVisible(true);
        frame.setVisible(false);
    }

}
