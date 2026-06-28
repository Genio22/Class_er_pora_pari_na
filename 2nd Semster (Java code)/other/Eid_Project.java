
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.IOException;

public class Eid_Project {

    public static void main(String[] args) {
        // Create Frame
        JFrame frame = new JFrame("Eid Mubarak");
        frame.setSize(800, 533);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        // Load Background Image
        JLabel backgroundLabel = new JLabel();
        try {
            Image background = ImageIO.read(new File("G:/ALL/Class_er_pora_pari_na/2nd Semster (Java code)/eid_background.jpg"));
            background = background.getScaledInstance(800, 533, Image.SCALE_SMOOTH);
            backgroundLabel.setIcon(new ImageIcon(background));
        } catch (IOException e) {
            System.out.println("Error: Image not found!");
            e.printStackTrace();
        }
        backgroundLabel.setBounds(0, 0, 800, 533);

        // Eid Greeting Message
        JLabel messageLabel = new JLabel("Eid Mubarak!");
        messageLabel.setFont(new Font("Serif", Font.BOLD, 30));
        messageLabel.setForeground(Color.BLACK);
        messageLabel.setBounds(300, 100, 300, 50);

        // Blinking Animation
        Timer timer = new Timer(500, e -> messageLabel.setVisible(!messageLabel.isVisible()));
        timer.start();

        // Close Button
        JButton closeButton = new JButton("Close");
        closeButton.setBounds(350, 300, 100, 40);
        closeButton.addActionListener(e -> frame.dispose());

        // Add Components
        frame.add(backgroundLabel);
        frame.add(messageLabel);
        frame.add(closeButton);

        // Ensure message and button are above the background
        frame.getContentPane().setComponentZOrder(backgroundLabel, 2);
        frame.getContentPane().setComponentZOrder(messageLabel, 0);
        frame.getContentPane().setComponentZOrder(closeButton, 1);

        frame.setVisible(true);
    }
}
