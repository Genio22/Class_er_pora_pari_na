/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

/**
 *
 * @author ahnaf
 */
public class Person {

    String name, address, email_address;
    String phone_num;

    public Person(String name, String address, String email_address, String phone_num) {
        this.name = name;
        this.address = address;
        this.email_address = email_address;
        this.phone_num = phone_num;
    }

    @Override
    public String toString() {
        return "Class: Person\n"
                + "Name: " + name + "\n"
                + "Address: " + address + "\n"
                + "Email: " + email_address + "\n"
                + "Phone: " + phone_num;
    }

}

class Student extends Person {

    String class_status;
    public static final String FRESHMAN = "Freshman";
    public static final String SOPHOMORE = "Sophomore";
    public static final String JUNIOR = "Junior";
    public static final String SENIOR = "Senior";


    /*
    public Student(String name, String address, String email_address, String phone_num) {
        super(name, address, email_address, phone_num);
        this.class_status = "freshman";
    }
     */
    public Student(String class_status, String name, String address, String phone_num, String email_address) {
        super(name, address, email_address, phone_num);
        this.class_status = class_status;// Avaiable -> freshman, sophomore, junior, or senior
    }

    @Override
    public String toString() {
        return "Class: Student\n"
                + "Name: " + name + "\n"
                + "Status: " + class_status + "\n"
                + "Address: " + address + "\n"
                + "Email: " + email_address + "\n"
                + "Phone: " + phone_num;
    }

}

class Employee extends Person {

    String office;
    double salary;
    String hired_date;

    public Employee(String office, double salary, String hired_date, String name, String address, String email_address, String phone_num) {
        super(name, address, email_address, phone_num);
        this.office = office;
        this.salary = salary;
        this.hired_date = hired_date;
    }

    @Override
    public String toString() {
        return "Class: Employee\n"
                + "Name: " + name + "\n"
                + "Office: " + office + "\n"
                + "Salary: " + salary + "\n"
                + "Hired Date: " + hired_date + "\n"
                + "Address: " + address + "\n"
                + "Email: " + email_address + "\n"
                + "Phone: " + phone_num;
    }

}

class Faculty extends Employee {

    String office_hour, rank;

    public Faculty(String office_hour, String rank, String office, double salary, String hired_date, String name, String address, String email_address, String phone_num) {
        super(office, salary, hired_date, name, address, email_address, phone_num);
        this.office_hour = office_hour;
        this.rank = rank;
    }

    @Override
    public String toString() {
        return "Class: Faculty\n"
                + "Name: " + name + "\n"
                + "Rank: " + rank + "\n"
                + "Office Hours: " + office_hour + "\n"
                + "Office: " + office + "\n"
                + "Salary: " + salary + "\n"
                + "Hired Date: " + hired_date + "\n"
                + "Address: " + address + "\n"
                + "Email: " + email_address + "\n"
                + "Phone: " + phone_num;
    }
}

class Staff extends Employee {

    String title;

    public Staff(String title, String office, double salary, String hired_date, String name, String address, String email_address, String phone_num) {
        super(office, salary, hired_date, name, address, email_address, phone_num);
        this.title = title;
    }

    @Override
    public String toString() {
        return "Class: Staff\n"
                + "Name: " + name + "\n"
                + "Title: " + title + "\n"
                + "Office: " + office + "\n"
                + "Salary: " + salary + "\n"
                + "Hired Date: " + hired_date + "\n"
                + "Address: " + address + "\n"
                + "Email: " + email_address + "\n"
                + "Phone: " + phone_num;
    }
}
