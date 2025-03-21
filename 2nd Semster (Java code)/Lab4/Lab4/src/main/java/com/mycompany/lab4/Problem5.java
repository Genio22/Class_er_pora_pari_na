/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab4;

import java.util.Scanner;

/**
 * to find the sum of numbers in a 2D array using a method. (Array should be
 * passed from main method)
 */
public class Problem5 {

    public static void array_sum(int rows, int cols, int[][] mat1) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += mat1[i][j];
            }
        }

        System.out.println("Sum: " + sum);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Size [][]: ");
        int rows = in.nextInt();
        int cols = in.nextInt();
        int[][] mat1 = new int[rows][cols];
        System.out.println("Enter the matrix: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat1[i][j] = in.nextInt();
            }
        }
        array_sum(rows, cols, mat1);

    }
}
