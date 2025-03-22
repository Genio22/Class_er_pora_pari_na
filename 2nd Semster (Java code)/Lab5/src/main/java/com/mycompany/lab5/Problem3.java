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
public class Problem3 {
    public static void palindrome(int num) {
        int a = num;
        int newr = 0;
        while (a != 0) {
            newr = (newr * 10) + (a % 10);
            a = a / 10;
        }
        if (num == newr) {
            System.out.println(num + " is a palindrome number.");
        } else {
            System.out.println(num + " is not a palindrome number.");
        }
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("Enter a number to check palindrome: ");
            int ori = in.nextInt();
            //in.close();
            palindrome(ori);
        }
    }
}
