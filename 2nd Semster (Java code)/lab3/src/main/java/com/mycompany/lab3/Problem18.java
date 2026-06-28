
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 *
 * Find the sum of numbers in an array.
 */
public class Problem18 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Size: ");
        int b = in.nextInt();
        int[] a = new int[b];
        int[] c = new int[b];
        for (int i = 0; i < b; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < b; i++) {
            c[i]= a[i];
            System.out.println(c[i]);
        }
        

    }

}
