/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 
 */
public class Problem20 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Size: ");
        int b = in.nextInt();
        int[] a = new int[b];
        int[] c = new int[b];
        int sum = 0;
        for (int i = 0; i < b; i++) {
            a[i] = (int) (Math.random() * 10);
            if (a[i] % 2 != 0) {

                c[i] = a[i];
                sum += c[i];
                System.out.println(c[i]);
            }
        }
        System.out.println("Sum: " +sum);

    }

}
