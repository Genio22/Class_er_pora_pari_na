package com.mycompany.lab2;

import java.util.Scanner;

/**
 * The area and perimeter of rectangle Test Data: Width = 5.5 Height = 8.5
 * Expected Output Area is 5.6 * 8.5 = 47.60, Perimeter is 2 * (5.6 + 8.5) =
 * 28.20
 */
public class Problem10 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter height: ");
        double height = input.nextDouble();

        System.out.print("Enter width: ");
        double width = input.nextDouble();
        double area = width * height;
        double perimeter = 2 * (width + height);

        System.out.println("Area: " + area);
        System.out.println("Perimeter: " + perimeter);
        input.close();
    }
}
