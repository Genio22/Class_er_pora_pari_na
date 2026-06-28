/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/*
 * Medium
Write a Bird class with a method makeSound(). Create two subclasses Parrot and Crow, override makeSound() in each, and test the output using a parent class reference.
 */
public class C_Problem2 {

    public static void main(String[] args) {
        Bird b = new Crow(); // Uppercasting
        Bird a = new Parrot();
        //Crow c = (Crow) a;

        a.makeSound();
        b.makeSound();
    }
}

class Bird {

    void makeSound() {
        System.out.println("Che Che");
    }
}

class Parrot extends Bird {

    @Override
    void makeSound() {
        System.out.println("Helloooo...");
    }
}

class Crow extends Bird {

    @Override
    void makeSound() {
        System.out.println("Cro Cro");
    }
}
