/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To find the multiplication table of n,where n is an integer variable for
 * which you have to take input from the console.
 */
public class Problem5 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter num 1: ");
        int n = in.nextInt();
        in.close();
        for (int i = 0; i <= 10; i++) {
            System.out.printf("%d X %d = %d\n", n, i, n * i);
        }
    }
}
