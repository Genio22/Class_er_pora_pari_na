/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

public class Problem1 {

    public static void main(String[] args) {
        Person[] people = new Person[5];

        people[0] = new Person("Md. Hasan", "Mirpur, Dhaka", "hasan.bd@example.com", "01711222333");
        people[1] = new Student(Student.SENIOR, "Uttara, Dhaka", "sadia.rahman@example.com", "01733445566", Student.JUNIOR);
        people[2] = new Employee("Admin Building, Room 302", 45000, "2021-06-15", "Abdullah Al Mamun", "Chattogram", "mamun.hr@example.com", "01733445562");
        people[3] = new Faculty("9AM - 1PM", "Assistant Professor", "Academic Building 2, Room 105", 82000, "2019-02-20", "Dr. Nusrat Jahan", "Sylhet", "nusrat.cse@universitybd.edu", "01733445561");
        people[4] = new Staff("Lab Technician", "Lab Building, Room 12", 37000, "2020-11-10", "Tariqul Islam", "Rajshahi", "tariqul.lab@example.com", "01733445560");

        System.out.println("=== Testing Polymorphism and toString() ===\n");

        for (Person p : people) {
            System.out.println(p); // Automatically calls overridden toString()
            System.out.println("--------------------------------------------------");
        }
    }
}
