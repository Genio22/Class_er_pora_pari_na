/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/*
🤖 Scenario: You're designing a robot that can speak, walk, and compute.
We’ll define:

An abstract class Robot (basic robot functions like boot()).

Interfaces Speaker and Walker for specific behaviors.

A concrete class AIHumanoid that combines everything.
 */
public class C_Problem7 {

    public static void main(String[] args) {
        AIHumanoid bot = new AIHumanoid();
        bot.boot();
        bot.compute();
        bot.speak();
        bot.walk();
    }
}

abstract class Robot {

    void boot() {
        System.out.println("Booting up........");
    }

    abstract void compute();

}

interface Speaker {

    void speak();
}

interface Walker {

    default void walk();
}

class AIHumanoid extends Robot implements Speaker, Walker {

    @Override
    void compute() {
        System.out.println("Performing computing......");
    }

    @Override
    public void speak() {
        System.out.println("Hello everyone.");
    }

    default void walk() {
        System.out.println("Initiating walking...");
    }
}
