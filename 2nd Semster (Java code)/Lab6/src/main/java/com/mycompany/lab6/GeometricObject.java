/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

import java.util.Date;

/**
 *
 * @author ahnaf
 */
public class GeometricObject {

    private String color;
    private Boolean filled;
    private Date dateCreated;
    //private Date dateCreated = new Date();

    public GeometricObject() {

    }

    public GeometricObject(String color, Boolean filled) {
        this.color = color;
        this.filled = filled;
        this.dateCreated = new Date();
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Boolean isFilled() {
        return filled;
    }

    public void setFilled(Boolean filled) {
        this.filled = filled;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    @Override
    public String toString() {
        return "Color: " + this.color + " Filled: " + this.filled + " Date: " + this.dateCreated;
    }
}

class Circle extends GeometricObject {

    private double radius;

    public Circle() {

    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle(double radius, String color, Boolean filled) {
        super(color, filled);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return 3.1416 * radius * radius;
    }

    public double getPerimeter() {
        return 2 * 3.1416 * radius;
    }

    public double getDiameter() {
        return 2 * radius;
    }

    public void printCircle() {
        System.out.printf("Circle:\nColor: %s,Filled: %b,Radius: %f, Diameter: %f\nArea: %f, Parimeter: %f", super.getColor(), super.isFilled(), this.radius, getDiameter(), getArea(), getPerimeter());
    }
}

class Rectangle extends GeometricObject {

    private double width, height;

    public Rectangle() {

    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public Rectangle(double width, double height, String color, Boolean filled) {
        super(color, filled);
        this.width = width;
        this.height = height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return 2 * (width * height);
    }
}
