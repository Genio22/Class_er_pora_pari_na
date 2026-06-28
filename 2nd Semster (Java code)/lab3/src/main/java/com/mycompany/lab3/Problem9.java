/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To find if a number is prime or not.
 */
public class Problem9 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number to check prime: ");
        int p = in.nextInt();
        boolean isprime = true;
        for (int i = 2; i <= p - 1; i++) {
            if (p % i == 0) {
                isprime = false;
            }
        }
        if (isprime) {
            System.out.println("It's a prime number.");
        } else {
            System.out.println("It's not a prime number.");
        }

    }
}
