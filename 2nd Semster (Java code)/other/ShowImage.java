
import javax.swing.*;

public class ShowImage {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Image Display");
        frame.setSize(800, 533);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Load Image
        String path = "C:\\Users\\ahnaf\\Downloads\\inline_image_preview.jpg";  // Change to your image path
        ImageIcon imageIcon = new ImageIcon(path);

        if (imageIcon.getIconWidth() == -1) {  // If image fails to load
            System.out.println("Error: Image not found at " + path);
            return;
        }

        JLabel label = new JLabel(imageIcon);
        frame.add(label);
        frame.setVisible(true);
    }
}
