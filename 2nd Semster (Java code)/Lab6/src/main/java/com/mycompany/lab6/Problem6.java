/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

/**
 *
 * @author ahnaf
 */
public class Problem6 {

    public static void main(String[] args) {
        // Creating a PremiumAccount
        PremiumAccount premiumAcc = new PremiumAccount("PA001", 1000.0, 0.05, 200.0, 300.0);

        // Showing initial details
        System.out.println("Account Number: " + premiumAcc.accNumber);
        System.out.println("Initial Balance: " + premiumAcc.balance);
        System.out.println("Interest Earned: " + premiumAcc.calculateInterest());
        System.out.println("Overdraft Exceeded? " + premiumAcc.checkOverdraft());

        // Performing deposit
        premiumAcc.deposit(500.0);
        System.out.println("Balance after deposit: " + premiumAcc.balance);

        // Performing withdrawal
        premiumAcc.withdraw(1800.0);  // This might go beyond overdraft limit
        System.out.println("Balance after withdrawal: " + premiumAcc.balance);
        System.out.println("Overdraft Exceeded? " + premiumAcc.checkOverdraft());

        // Redeeming rewards
        premiumAcc.redeemRewards(100.0);  // Sufficient reward points
        System.out.println("Remaining Reward Points: " + premiumAcc.rewardPoints);

        premiumAcc.redeemRewards(200.0);  // Insufficient reward points
        System.out.println("Remaining Reward Points: " + premiumAcc.rewardPoints);
    }
}
