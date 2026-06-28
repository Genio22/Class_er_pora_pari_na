/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
 * @author ahnaf
 */
public class oProblem3 {

    public static void main(String[] args) {
        Stock s = new Stock("ORCL", "Oracle Corporation");
        s.setPreviousClosingPrice(34.5);
        s.setCurrentPrice(34.35);
        System.out.println("The price change percentage " + s.getChangePercent() + "%");
    }
}
