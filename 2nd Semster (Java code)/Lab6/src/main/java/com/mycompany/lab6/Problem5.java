/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

/**
 *
 * @author User
 */
public class Problem5 {

    public static void main(String[] args) {
        SavingsAccount s1 = new SavingsAccount(7, "aer324te2", "Doramon", 2000);
        String a = s1.toString();
        System.out.println(a);

        FixedDepositAccount f1 = new FixedDepositAccount(5, 7, "aer324te2", "Doramon", 2000);
        System.out.println(f1.toString());
    }
}
