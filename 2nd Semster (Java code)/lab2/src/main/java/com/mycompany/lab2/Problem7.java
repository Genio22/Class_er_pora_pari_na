package com.mycompany.lab2;

import java.util.Scanner;

/*
 Body Mass Index (BMI) is a measure of health on weight. 
 It can be calculated by taking your weight in kilograms and 
 dividing by the square of your height in meters(1 inches=2.54cm). The interpretation of BMI for people 16 years or older is as follows:
 */
public class Problem7 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter weight (kg): ");
        double weight = input.nextDouble();

        System.out.print("Enter height (m): ");
        double height = input.nextDouble();
        double bmi = weight / (height * height);

        System.out.println("BMI: " + bmi);

        if (bmi < 18.5) {
            System.out.println("under weight,ar diet koiren na 😊");
        } else if (bmi < 25) {
            System.out.println(" Normal weight");
        } else if (bmi < 30) {
            System.out.println("Overweight,diet shuru koren😊");
        } else {
            System.out.println("You are Obese :)");
        }
    }
}
