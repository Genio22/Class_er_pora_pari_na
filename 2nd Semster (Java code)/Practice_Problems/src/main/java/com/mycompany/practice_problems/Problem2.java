/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/**
 *
 * @author ahnaf
 */
public class Problem2 {

    public static void main(String[] args) {
        Bird b = new Crows(); // Uppercasting
        Bird a = new Parrot();
        //Crows c = (Crows) a;

        a.makeSound();
        // downcasting experiment
        if (b instanceof Crows) {
            Crows c = (Crows) b;
            c.makeSounds();
        }
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

class Crows extends Bird {

    //@Override
    void makeSounds() {
        System.out.println("Cro Cro");
    }
}
