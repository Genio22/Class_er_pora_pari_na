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
public class Problem15 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double lon = in.nextInt();
        double time = in.nextInt();
        double yirate = in.nextInt();

        double r = yirate / 1200;
        double n = time * 12;
        double M = (lon * r) / (1 - (1 / Math.pow((1 + r), n)));
        System.out.println("Monthly Payment: " + M);
        System.out.println("Total Payment: " + (M * 12));
        double balance = lon;
        System.out.println("Payment#         Interest            Principal            Balance\n");
        for (int i = 1; i <= time * 12; i++) {
            double inter = balance * r;

            double principal = M - inter;

            balance -= principal;

            System.out.println(i + "         " + inter + "        " + principal + "       " + balance);

        }
        //System.out.println(M);
    }
}
