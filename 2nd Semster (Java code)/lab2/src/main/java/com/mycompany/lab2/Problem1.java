package com.mycompany.lab2;

import java.util.Scanner;

/*
 * To Find out if a character is a vowel or consonant.
 */
public class Problem1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a characer: ");
        char ch = in.next().charAt(0);
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
        in.close();
    }
}
