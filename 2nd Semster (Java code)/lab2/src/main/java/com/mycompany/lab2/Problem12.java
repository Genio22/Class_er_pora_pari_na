package com.mycompany.lab2;

import java.util.Scanner;

/**
 * Write a Java program to calculate the sum of two integers and return true if
 * the sum is equal to a third integer. Take the integers input from console.
 * Sample Output: Input the first number : 5 Input the second number: 10 Input
 * the third number : 15
 *
 */
public class Problem12 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int a = input.nextInt();

        System.out.print("Enter the second number: ");
        int b = input.nextInt();

        System.out.print("Enter the third number: ");
        int c = input.nextInt();

        if ((a + b) == c) {
            System.out.print("True");
        } else {
            System.out.println("False");
        }
    }

}
