/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/*
 *Find the following formation with an input taken from the console
 *n=4
 *0 1 0 1
 *0 1 0
 *1 0 
 *1
 */
public class Problem13 {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        /* // trial -1    
        int count = 1;
        double c1 = 1;
        int c2 = 0;
        for (int i = a; i >= 1; i--) {

            if (count <= 2) {

                if (c1 % 2 != 0) {
                    for (int j = 1; j <= i; j++) {
                        if (j % 2 == 0) {
                            System.out.print("1");
                        } else {
                            System.out.print("0");
                        }
                    }
                    System.out.println("");
                    count++;
                    c1 = c1 + 0.5;
                    c2 = (int) c1; //typecasting double to int
                    //System.out.println(c2);
                } else if (c2 % 2 == 0) {
                    for (int j = 1; j <= i; j++) {
                        if (j % 2 == 0) {
                            System.out.print("0");
                        } else {
                            System.out.print("1");
                        }
                    }
                    System.out.println("");
                    count++;
                    //c1 = c1 + 0.5;
                }

            }
            count = 1;

        }
         */
        // trial 2
        //for (int q = 1; q <= 2; q = q - 2) 
        int k = 10;
        int p = a;
        while (p >= 1) {
            //for (int i = 1; i <= 2; i++) {
            if (k % 2 == 0) {
                for (int j = 1; j <= p; j++) {
                    if (j % 2 == 0) {
                        System.out.print("1");
                    } else {
                        System.out.print("0");
                    }
                }
                System.out.println("");
                k = 9;
            } else {
                for (int j = 1; j <= p; j++) {
                    if (j % 2 == 0) {
                        System.out.print("0");
                    } else {
                        System.out.print("1");
                    }
                }
                System.out.println("");
                k = k - 2;
            }
            //}
            p--;

        }
    }
}
