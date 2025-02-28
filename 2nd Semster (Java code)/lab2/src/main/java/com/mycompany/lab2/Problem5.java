package com.mycompany.lab2;

import java.util.Scanner;

/*
Finds the maximum among 3 numbers(from console).
 */
public class Problem5 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter 3 number: ");
        double a = in.nextDouble();
        double b = in.nextDouble();
        double c = in.nextDouble();
        if (a > b) {
            if (a > c) {
                System.out.println(a + " is largest number.");
            } else {
                System.out.println(c + " is largest number.");
            }
        } else {
            if (b > c) {
                System.out.println(b + " is largest number.");
            } else {
                System.out.println(c + " is largest number.");
            }
        }

    }
}
