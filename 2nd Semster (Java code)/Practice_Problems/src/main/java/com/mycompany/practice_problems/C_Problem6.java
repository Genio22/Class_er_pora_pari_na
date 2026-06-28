/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/**
 *
 * @author ahnaf
 */
public class C_Problem6 {

    public static void main(String[] args) {
        Shape[] r = new Shape[3];
        r[0] = new Rectangle(3, 4);
        r[1] = new Circle(4.5);
        r[2] = new Triangles(4, 3);
        for (Shape t : r) {
            if (t instanceof Circle) {
                System.out.println("Circle Area: " + t.getArea());
            } else if (t instanceof Rectangle) {
                System.out.println("Rectangle Area: " + t.getArea());
            } else if (t instanceof Triangles) {
                System.out.println("Triangle Area: " + t.getArea());
            }
        }

    }
}

abstract class Shape {

    abstract double getArea();

}

class Rectangle extends Shape {

    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return this.length * this.width;
    }
}

class Circle extends Shape {

    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return 3.1416 * radius * radius;
    }

}

class Triangles extends Shape {

    double base, height;

    public Triangles(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double getArea() {
        return 0.5 * this.base * this.height;
    }
}
