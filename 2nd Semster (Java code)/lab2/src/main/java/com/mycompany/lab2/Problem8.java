package com.mycompany.lab2;

/**
 * Determines a year is leap year or not
 */
import java.util.Scanner;

public class Problem8 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter year: ");
        int year = input.nextInt();

        boolean leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
        if (leap) {
            System.out.println(year + " is a leap year");
        } else {
            System.out.println(year + " is not a leap year");
        }
    }
}
