/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/*
Design a class named Stock that contains:
■ A string data field named “symbol” for the stock’s symbol.
■ A string data field named “name” for the stock’s name.
■ A double data field named previousClosingPrice that stores the stock price for the previous day.
■ A double data field named currentPrice that stores the stock price for the current time.
■ A constructor that creates a stock with the specified symbol and name.
■ A method named getChangePercent() that returns the percentage changed
from previousClosingPrice to currentPrice.
Write a test program that creates a Stock object with the stock symbol ORCL, the name
Oracle Corporation, and the previous closing price of 34.5. Set a new current price to 34.35 and display the price-change percentage.

 */
public class Stock {

    private String symbol, name;
    private double previousClosingPrice, currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    public void setPreviousClosingPrice(double previousClosingPrice) {
        this.previousClosingPrice = previousClosingPrice;
    }

    public void setCurrentPrice(double currentPrice) {
        this.currentPrice = currentPrice;
    }

    public double getChangePercent() {
        return ((previousClosingPrice - currentPrice) / previousClosingPrice) * 100;
    }

}
