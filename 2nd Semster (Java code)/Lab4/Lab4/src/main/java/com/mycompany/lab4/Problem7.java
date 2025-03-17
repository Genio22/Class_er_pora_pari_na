/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab4;

import java.util.Scanner;

/**
 * Write a method that takes an array of integers input. And returns a random
 * number between 1 and 54, excluding the numbers passed in the argument. The
 * method header is specified as follows: public static int getRandom(int...
 * numbers)
 *
 */
public class Problem7 {

    public static int getRandom(int[] ex_va) {
        boolean get = false;
        int a = -1;
        while (!get) {
            a = (int) (Math.random() * (54));
            for (int elem : ex_va) {
                if (a != elem && 0 < a) {
                    get = true;
                }
            }
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //int s = in.nextInt();
        int e = in.nextInt();
        int[] ex_va = new int[e];
        System.out.print("Enter the numbers: ");
        for (int i = 0; i < e; i++) {
            ex_va[i] = in.nextInt();
        }
        int b = getRandom(ex_va);
        System.out.println("Result: " + b);
    }
}
