/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

/**
 *
 * @author ahnaf
 */
public class Problem2 {

    public static void main(String[] args) {
        GeometricObject geometry = new GeometricObject("Red", true);
        System.out.println("\n---- GeometricObject Info ----");
        System.out.println(geometry);
        System.out.println();

        Circle circle = new Circle(5.5, "Blue", true);
        System.out.println("---- Circle Info ----");
        circle.printCircle();

        System.out.println(); // For spacing

        Rectangle rectangle = new Rectangle(4.0, 7.5, "Red", false);
        System.out.println("\n---- Rectangle Info ----");
        System.out.printf("Color: %s, Filled: %b\n", rectangle.getColor(), rectangle.isFilled());
        System.out.printf("Width: %.2f, Height: %.2f\n", rectangle.getWidth(), rectangle.getHeight());
        System.out.printf("Area: %.2f, Perimeter: %.2f\n", rectangle.getArea(), rectangle.getPerimeter());
    }
}
