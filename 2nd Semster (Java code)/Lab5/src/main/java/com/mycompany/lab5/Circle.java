/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

/**
 *
Write a test program that creates two Circle objects—one with radius 4.5
and the other with radius 3.7. Display the radius, area,
and perimeter of each Circle in this order.

 */
public class Circle {
    private double radius = 1;

    public Circle(double newRadius) {
        this.radius = newRadius;
    }


    public double getArea() {
        return Math.PI * radius * radius;
    }


    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    public void setRadius(double newRadius) {
        this.radius = newRadius;
    }


    public void displayCircle() {
        System.out.println("Radius: " + radius);
        System.out.println("Area: " + getArea());
        System.out.println("Perimeter: " + getPerimeter());
        System.out.println();
    }

}
