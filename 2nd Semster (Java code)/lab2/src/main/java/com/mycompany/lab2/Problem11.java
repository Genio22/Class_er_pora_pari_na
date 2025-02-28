package com.mycompany.lab2;

/*
 * Write a Java program to swap two variables.
 */
import java.util.Scanner;

public class Problem11 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter 1st number: ");
        double a = input.nextDouble();

        System.out.print("Enter 2nd number: ");
        double b = input.nextDouble();
        System.out.println("Old-> a: " + a + " b: " + b);
        double c = b;
        b = a;
        a = c;

        System.out.println("-> a: " + a + " b: " + b);

    }
}
