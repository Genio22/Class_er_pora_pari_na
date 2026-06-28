/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

import java.util.Scanner;

/**
 *
 * @author ahnaf
 */
public class Problem2 {
    
    public static void power() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the base number: ");
        int base = in.nextInt();
        System.out.print("Enter the exponent number: ");
        int exp = in.nextInt();
        in.close();
        int result = 1;
        for (int i = 1; i <= exp; i++) {
            result *= base;
        }
        System.out.println("The result is: " + result);
    }

    public static void main(String[] args) {
        power();
    }
}
