package com.mycompany.lab2;

import java.util.Scanner;

/*
Finds if a triangle is scalene, isosceles or equilateral, with 3 arms(from console) given
 */
public class Problem6 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double a, b, c;
        System.out.println("Enter 3 side of triangle");
        System.out.print("-> ");
        a = in.nextDouble();
        System.out.print("-> ");
        b = in.nextDouble();
        System.out.print("-> ");
        c = in.nextDouble();
        boolean d = (a + b > c) && (b + c > a) && (c + a > b);

        if (d && ((a == b) || (b == c) || (c == a))) {
            System.out.println("It is a isosceles triangle");
        } else if (d && !((a == b) || (b == c) || (c == a))) {
            System.out.println("It is a scalene triangle");
        } else if (d && ((a == b) && (b == c))) {
            System.out.println("It is a equilateral triangle");
        } else {
            System.out.println("It is not a triangle");

        }
        in.close();
    }
}
