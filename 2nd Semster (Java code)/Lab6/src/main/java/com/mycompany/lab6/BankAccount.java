/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

/**
 *
 * @author User
 */
public abstract class BankAccount {

    private String accNumber, accHolderName;
    private double balance;

    public BankAccount(String accNumber, String accHolderName, double balance) {
        this.accNumber = accNumber;
        this.accHolderName = accHolderName;
        this.balance = balance;
    }

    public String getAccNumber() {
        return accNumber;
    }

    public void setAccNumber(String accNumber) {
        this.accNumber = accNumber;
    }

    public String getAccHolderName() {
        return accHolderName;
    }

    public void setAccHolderName(String accHolderName) {
        this.accHolderName = accHolderName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
    

    public abstract void deposite(double amount);

    public abstract void withdraw(double amount);

    public void displayAccountInfo() {

    }

}

class SavingsAccount extends BankAccount {

    private double interestRate;

    public SavingsAccount(double interestRate, String accNumber, String accHolderName, double balance) {
        super(accNumber, accHolderName, balance);
        this.interestRate = interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    @Override
    public void deposite(double amount) {

    }

    @Override
    public void withdraw(double amount) {

    }

    public void calculateYearlyInterest() {

    }

    @Override
    public String toString() {
        return "SavingsAccount{" + "interestRate=" + this.interestRate + '}';
    }
    
}

class FixedDepositAccount extends SavingsAccount {

    private int termInYears;

    public FixedDepositAccount(int termInYears, double interestRate, String accNumber, String accHolderName, double balance) {
        super(interestRate, accNumber, accHolderName, balance);
        this.termInYears = termInYears;
    }


    public int getTermInYears() {
        return termInYears;
    }

    public void setTermInYears(int termInYears) {
        this.termInYears = termInYears;
    }

    @Override
    public String toString() {
        return "FixedDepositAccount{" + "termInYears=" + this.termInYears + '}';
    }

    public void calculateMaturityAmount() {

    }
}
