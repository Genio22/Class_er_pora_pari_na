/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * Find the following formation with an input taken from the console n=4 1111
 * 2222 3333 4444
 *
 */
public class Problem14 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= 4; j++) {
                System.out.print(i);
            }
            System.out.println("");
        }
    }
}
