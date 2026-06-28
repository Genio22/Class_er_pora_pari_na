/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/*Create a main method to demonstrate:

Instantiate at least one Animal, Mammal, Bird, and Robot.

Use the reference type to test polymorphism with method calls (e.g., print the output of speak(), move(), and fly()).

Show how static methods behave when accessed through different reference types.
 */
public class C_Problem8 {

    public static void main(String[] args) {
        Animal a = new Mammal();
        a.move();
        if (a instanceof Mammal) {
            Mammal m = (Mammal) a; // downcasting
            m.speak(); // mammal

        } else if (a instanceof Bird b) {
            b.speak();
        }
        Mammal m = new Mammal();
        //m.speak(); // mammal
        m.move(); // mammal
    }

}

class Animal {

    void speak() {

        System.out.println("The animal makes a sound");
    }

    static void move() {
        System.out.println("Animal moves");
    }
}

class Mammal extends Animal {

    void speak() {
        System.out.println("The mammal speaks");
    }

    static void move() {
        System.out.println("Mammal runs");
    }
}

interface Flyable {

    void fly();
}

class Bird extends Animal implements Flyable {

    void speak() {
        System.out.println("The Bird chirps.");
    }

    public void fly() {
        System.out.println("The bird flies");
    }

}

class Robot implements Flyable {

    void move() {
        System.out.println("The robot moves");
    }

    public void fly() {
        System.out.println("The robot flies");
    }
}
