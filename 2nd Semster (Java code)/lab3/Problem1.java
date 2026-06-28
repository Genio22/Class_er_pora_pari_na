/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To take a number input and find the sum of the digits.
 */
public class Problem1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = in.nextInt();
        int sum = 0;
        int a = 1;
        while (a != 0) {
            a = num % 10;
            sum += a;
            num = num / 10;
        }
        System.out.println("Sum: " + sum);
        in.close();

    }
}
