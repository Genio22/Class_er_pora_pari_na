/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/*
    Given classes Animal, Dog, and Cat, write a function speak(Animal a) that prints 
    output depending on which subclass is passed. Use Animal a = new Dog(); and a = new Cat(); in main().
 */
public class C_Problem4 {

    // Static method can be called without object
    public static void main(String[] args) {
        Animal a = new Dog();
        speak(a);
        a = new Cat();
        speak(a);
    }

    public static void speak(Animal a) { //That method will accept an object of type Animal (or any subclass of Animal)
        if (a instanceof Dog) {
            System.out.println("Bark Bark..");
        } else if (a instanceof Cat) {
            System.out.println("Meaw Meaw..");
        } else {
            System.out.println("Sound...");
        }
    }
    /* 
    // non-static → you need to create an object to call them
    public static void main(String[] args) {
        C_Problem4 b = new C_Problem4();
        Animal a = new Dog();
        b.speak(a);
        a = new Cat();
        b.speak(a);
    }

    public void speak(Animal a) { //That method will accept an object of type Animal (or any subclass of Animal)
        if (a instanceof Dog) {
            System.out.println("Bark Bark..");
        } else if (a instanceof Cat) {
            System.out.println("Meaw Meaw..");
        } else {
            System.out.println("Sound...");
        }
    }
     */

}

class Animal {
}

class Dog extends Animal {
}

class Cat extends Animal {
}
