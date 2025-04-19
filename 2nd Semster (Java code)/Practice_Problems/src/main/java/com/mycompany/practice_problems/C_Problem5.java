/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.practice_problems;

/**
 *
 * @author ahnaf
 */
public class C_Problem5 {

    public static void main(String[] args) {
        a(new Person());
        a(new Student());
        a(new GraduateStudent());
        a(new Red());
    }

    public static void a(Object q) {
        System.out.println(q.toString());
    }
}

class Person {

    @Override
    public String toString() {
        return "This is Person";
    }
}

class Student extends Person {

    @Override
    public String toString() {
        return "Student";
    }

}

class GraduateStudent extends Person {

    @Override
    public String toString() {
        return "Graduate Student";
    }

}

class Red extends Person {

    //@Override
    public String toStrin() {
        return "Hi, Hello";
    }

}
