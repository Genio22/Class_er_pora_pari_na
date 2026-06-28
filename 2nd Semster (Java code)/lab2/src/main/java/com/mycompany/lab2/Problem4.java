package com.mycompany.lab2;

import java.util.Scanner;

/*
 * If a triangle is equilateral or not, with 3 arms(from console) given.
 */
public class Problem4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double a, b, c;
        System.out.println("Enter 3 side of triangle");
        System.out.print("-> ");
        a = input.nextDouble();
        System.out.print("-> ");
        b = input.nextDouble();
        System.out.print("-> ");
        c = input.nextDouble();
        boolean d = (a + b > c) && (b + c > a) && (c + a > b);
        if (d && ((a == b) || (b == c) || (c == a))) {

            System.out.println("It is a isosceles triangle");

        } else if (d && !((a == b) || (b == c) || (c == a))) {
            System.out.println("It is not a isosceles triangle");
        } else {
            System.out.println("It is not a triangle");
        }

    }
}
