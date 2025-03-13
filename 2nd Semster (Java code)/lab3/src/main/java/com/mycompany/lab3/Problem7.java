/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * that prompts the user to input an integer and then outputs the number with
 * the digits reversed. For example, if the input is 12345, the output should be
 * 54321.
 */
public class Problem7 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number to reverse: ");
        int a = in.nextInt();
        in.close();
        System.out.print("\n\nOriginal: " + a);
        int b = 1;
        System.out.print("\nModified: ");
        while (a != 0) {
            b = a % 10;
            a /= 10;
            System.out.print(b);
        }
    }
}
