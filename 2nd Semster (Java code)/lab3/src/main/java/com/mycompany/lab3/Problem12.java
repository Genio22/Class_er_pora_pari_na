/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/*
 *Find the following formation with an input taken from the console
 *n=4
 *0
 *1 0
 *0 1 0
 *1 0 1 0
 */
public class Problem12 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        for (int i = 1; i <= a; i++) {
            if (i % 2 == 0) {
                for (int j = 1; j <= i; j++) {
                    if (j % 2 == 0) {
                        System.out.print("0");
                    } else {
                        System.out.print("1");
                    }
                }
                System.out.println("");
            } else {
                for (int j = 1; j <= i; j++) {
                    if (j % 2 == 0) {
                        System.out.print("1");
                    } else {
                        System.out.print("0");
                    }
                }
                System.out.println("");
            }
        }
    }
}
