/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

/**
 * To find the prime numbers between 6-30.
 */
public class Problem10 {

    public static void main(String[] args) {
        for (int j = 6; j <= 30; j++) {
            boolean isprime = true;
            for (int i = 2; i <= j - 1; i++) {
                if (j % i == 0) {
                    isprime = false;
                }
            }
            if (isprime) {
                System.out.println(j);
            }
        }
    }
}
