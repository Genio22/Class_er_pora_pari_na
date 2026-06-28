/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

/**
 * To find the factorial value of any number entered through the keyboard.
 */
public class Problem6 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number for factorial: ");
        int p = in.nextInt();
        in.close();
        int mul = 1;
        switch (p) {
            case 0:
                System.out.println(p + "!  =  1");
                break;
            case 1:
                System.out.println(p + "! = 1");
                break;
            default:
                for (int i = 1; i <= p; i++) {
                    mul *= i;
                }
                System.out.println(p + "! = " + mul);
                break;
        }
    }
}
