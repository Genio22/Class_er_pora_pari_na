/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

/**
 * To find the odd numbers between 2-31.
 */
public class Problem3 {

    public static void main(String[] args) {
        int[] a = new int[30];
        int x = 1;
        for (int i = 2; i <= 31; i++) {
            if (i % 2 != 0) {
                a[x] = i;
                x++;
            }
        }
        for (int y : a) {
            if (y != 0) {
                System.out.println(y);
            }
        }
    }
}
