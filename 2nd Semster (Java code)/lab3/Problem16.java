/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

import java.util.Scanner;

public class Problem16 {
    public static void main(String[] args) {
        
    
       Scanner in = new Scanner(System.in);


        System.out.print("Loan Amount: ");
        double lon = in.nextDouble();

        System.out.print("Number of Years: ");
        double time = in.nextDouble();


        System.out.println("Interest Rate   Monthly Payment   Total Payment");

       
        for (double q = 5; q <= 8; q += 0.125) {
            double r = q / 1200;  
            double n = time * 12;  
            double M = (lon * r) / (1 - Math.pow(1 + r, -n));  
            double totalPayment = M * n;  

            
            System.out.printf("%.3f%%           %.2f           %.2f\n", q, M, totalPayment);
        }
    }
}
