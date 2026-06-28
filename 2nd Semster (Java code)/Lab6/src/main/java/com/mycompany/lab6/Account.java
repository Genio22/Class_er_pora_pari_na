/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.lab6;

/**
 *
 * @author User
 */
public class Account {

    String accNumber;
    double balance;

    Account(String accNumber, double balance) {
        this.accNumber = accNumber;
        this.balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
}

class SavingAccount extends Account {

    double interestRate;

    SavingAccount(String accNumber, double balance, double interestRate) {
        super(accNumber, balance);
        this.interestRate = interestRate;
    }

    double calculateInterest() {
        return balance + balance * interestRate;
    }
}

class CurrentAccount extends Account {

    double overDraftLimit;

    CurrentAccount(String accNumber, double balance, double overDraftLimit) {
        super(accNumber, balance);
        this.overDraftLimit = overDraftLimit;
    }

    boolean checkOverdraft() {
        return balance <= overDraftLimit;
    }

}

interface OverDraft {

    boolean checkOverdraft();
}

class PremiumAccount extends SavingAccount implements OverDraft {

    double rewardPoints;
    double overDraftLimit;

    PremiumAccount(String accNumber, double balance, double interestRate, double rewardPoints, double overDraftLimit) {
        super(accNumber, balance, interestRate);
        this.rewardPoints = rewardPoints;
        this.overDraftLimit = overDraftLimit;
    }

    @Override
    public boolean checkOverdraft() {
        return balance <= overDraftLimit;
    }

    void redeemRewards(double rewardamount) {
        if (rewardamount <= rewardPoints) {
            rewardPoints -= rewardamount;
        } else {
            System.out.println("Sorry your reward point is low");
        }
    }
}
