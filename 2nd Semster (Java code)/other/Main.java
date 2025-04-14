import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Edit your logic here
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a character: ");
        char ch = input.next().charAt(0);
        boolean a = Character.isLetter(ch);
        if (a) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                System.out.println("'" + ch + "' is a Vowel");
            } else {
                System.out.println("'" + ch + "' is a Consonant");
            }
        } else {
            System.out.println("'" + ch + "' is not a letter.");
        }
    }
}
        