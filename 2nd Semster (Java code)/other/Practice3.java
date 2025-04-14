/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.practice;

/*
  6.18 (Check password) Some websites impose certain rules for passwords. Write
  a method that checks whether a string is a valid password. Suppose the
  password rules are as follows: 
  ■ A password must have at least eight characters. 
  ■ A password consists of only letters and digits. 
  ■ A password must contain at least two digits. Write a program that prompts the user to
  enter a password and displays Valid Password if the rules are followed or
  Invalid Password otherwise.
 */
import java.util.Scanner;

public class Practice3 {

    public static boolean check_pass(String pass) {

        int b = 0;
        //boolean passok = false;
        if (pass.length() < 8) {
            System.out.println("Pass must be 8 character.");
            return false;
        }
        for (int i = 0; i < pass.length(); i++) {
            if (!Character.isLetterOrDigit(pass.charAt(i))) {
                System.out.println("Pass can not have any thing else but alphabate and digit");
                return false;
            }
            if (Character.isDigit(pass.charAt(i))) {
                b++;
            }

        }

        if (b < 2) {
            System.out.println("Pass must contain atleast 2 digit");
            return false;

        }
        return true;

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String pass = in.nextLine();

        boolean c = check_pass(pass);
        if (c) {
            System.out.println("Your passed is ok and saved.");

        }
    }
}
