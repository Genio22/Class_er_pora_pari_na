/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To take a number input, find the first and last digit of the number.
 */
public class Problem2 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = in.nextInt();
        in.close();
        int last = num % 10;
        int a = 1;

        while (num != 0) {
            a = num % 10;

            num = num / 10;
        }
        System.out.println("First digit: " + a);
        System.out.println("Last digit: " + last);
        in.close();
    }
}
