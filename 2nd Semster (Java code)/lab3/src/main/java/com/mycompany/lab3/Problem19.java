/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 *
 * @author User
 */
public class Problem19 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Size: ");
        int b = in.nextInt();
        int[] a = new int[b];


        for (int i = 0; i < b; i++) {
            a[i] = (int) (Math.random() * 10);
            if (a[i] % 2 == 0&& a[i] !=0 ) {


                System.out.println(a[i]);
            }
        }
    }

}
