package com.mycompany.practice_problems;

/*
 *  Basic
Create a Vehicle class with a run() method. Override it in a Car class to display "Car is running safely".
 */
public class C_Problem1 {

    public static void main(String[] args) {
        Vehicle v = new Car();
        v.run();
    }
}

class Vehicle {

    void run() {
        System.out.println("Vehicle is runing");
    }
}

class Car extends Vehicle {

    @Override
    void run() {
        System.out.println("Car is running safely");
    }
}
