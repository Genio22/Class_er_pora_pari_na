/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/**
 * i want to practice multi level inheritance
 */
// Multi-level inheritance example in Java
// In this example, we have a grandparent class, a parent class, and a child class.
// Parent class
class Grandparent {

    String name;

    public Grandparent(String name) {
        this.name = name;
    }

    public void displayGrandparentInfo() {
        System.out.println("Grandparent Name: " + name);
    }
}
// Parent class

class Parent extends Grandparent {

    int age;

    public Parent(String name, int age) {
        super(name); // Call the constructor of the grandparent class
        this.age = age;
    }

    public void displayParentInfo() {
        System.out.println("Parent Name: " + super.name + ", Age: " + age);
    }
}

// Child class
class Child extends Parent {

    String grade;

    public Child(String name, int age, String grade) {
        super(name, age); // Call the constructor of the parent class
        this.grade = grade;
    }

    public void displayChildInfo() {
        System.out.println("Child Name: " + name + ", Age: " + age + ", Grade: " + grade);
    }
}

public class Problem1 {

    public static void main(String[] args) {
        // Create an instance of the child class
        Child child = new Child("John", 10, "A+");

        // Call methods from the child class and parent classes
        child.displayChildInfo();
        child.displayParentInfo();
        child.displayGrandparentInfo();
    }
}
