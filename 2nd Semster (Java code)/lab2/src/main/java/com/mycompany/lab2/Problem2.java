
package com.mycompany.lab2;

import java.util.Scanner;
/*
 * Finds if 3 arms(from console) can make a triangle or not.
 */
public class Problem2 {
    public static void main(String[] args) {
        Scanner input;
        input = new Scanner(System.in);
        double a, b, c;
        System.out.println("Enter 3 side of triangle");
        System.out.print("-> ");
        a = input.nextDouble();
        System.out.print("-> ");
        b = input.nextDouble();
        System.out.print("-> ");
        c = input.nextDouble();
        boolean d = (a + b > c) && (b + c > a) && (c + a > b);
        if (d){
            System.out.println("It is a triangle");
        }
        else{
            System.out.println("It is not a triangle");
        }

    }
}
