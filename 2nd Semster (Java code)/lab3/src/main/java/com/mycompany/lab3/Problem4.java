/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To find the odd numbers between m-n,where m and n are two integer variables
 * for which you have to take input from the console
 */
public class Problem4 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter num 1: ");
        int m = in.nextInt();
        System.out.print("Enter num 2: ");
        int n = in.nextInt();
        int[] a = new int[30];
        int x = 1;
        for (int i = m; i <= n; i++) {
            if (i % 2 != 0) {
                a[x] = i;
                x++;
            }
        }
        System.out.printf("All odd numbers between %d and %d", m, n);
        for (int y : a) {
            if (y != 0) {
                System.out.println(y);
            }
        }
    }
}
