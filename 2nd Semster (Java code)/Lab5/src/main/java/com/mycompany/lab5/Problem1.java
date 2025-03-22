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
public class Problem1 {
    public static void checkevenodd() {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        in.close();
        if (num % 2 == 0) {
            System.out.println("The number is even");
        } else {
            System.out.println("The number is odd");
        }
    }

    public static void main(String[] args) {
        checkevenodd();
    }
}
