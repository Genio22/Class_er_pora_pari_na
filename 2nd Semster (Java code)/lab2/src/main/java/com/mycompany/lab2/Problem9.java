package com.mycompany.lab2;

import java.util.Scanner;

/**
 * The area and perimeter of circle Test Data: Radius = 7.5 Expected Output
 * Perimeter is = 47.12388980384689, Area is = 176.71458676442586
 *
 */
public class Problem9 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter radius: ");
        double radius = input.nextDouble();

        double area = 3.1416 * (radius * radius);
        double circumference = 2 * 3.1416 * radius;

        System.out.print("Area: " + area);
        System.out.print("Circumference: " + circumference);
    }
}
