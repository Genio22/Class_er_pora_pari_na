package com.mycompany.lab2;

import java.util.Scanner;

/**
 * To create the grading system of East West University
 */
public class Problem13 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the mark: ");
        double mark = in.nextDouble();
        // Grading system of East West University   
        if (80 <= mark && mark <= 100) {
            System.out.println("Grade: A+");
        } else if (75 <= mark && mark <= 79) {
            System.out.println("Grade: A");
        } else if (70 <= mark && mark <= 74) {
            System.out.println("Grade: A-");
        } else if (65 <= mark && mark <= 69) {
            System.out.println("Grade: A");
        } else if (60 <= mark && mark <= 64) {
            System.out.println("Grade: B+");
        } else if (55 <= mark && mark <= 59) {
            System.out.println("Grade: B");
        } else if (50 <= mark && mark <= 54) {
            System.out.println("Grade: B-");
        } else if (45 <= mark && mark <= 49) {
            System.out.println("Grade: C+");
        } else if (40 <= mark && mark <= 44) {
            System.out.println("Grade: D");
        } else {
            System.out.println("Grade: F");
        }
    }

}
