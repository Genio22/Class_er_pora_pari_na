/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab4;

import java.util.Scanner;

/**
 * to find the multiplication and summation of two matrices using 2 different
 * methods.(sizes of matrices and inputs into the matrices from console)
 */
public class Problem4 {

    public static void matrix_mul(int rows, int cols, int[][] mat1, int[][] mat2) {
        int[][] resultm = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //resultm[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    resultm[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        System.out.println("The multiplication of the two matrices is: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(resultm[i][j] + " ");
            }
            System.out.println();
        }
        //return resultm[rows][cols];
    }

    public static void matrix_sum(int rows, int cols, int[][] mat1, int[][] mat2) {
        int[][] resultm = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                //resultm[i][j] = 0;

                resultm[i][j] = mat1[i][j] + mat2[i][j];

            }
        }
        System.out.println("The Summation of the two matrices is: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(resultm[i][j] + " ");
            }
            System.out.println();
        }
        //return resultm[rows][cols];
    }

    public static void main(String[] args) {
        int rows, cols;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of rows and columns of the matrices: ");
        rows = input.nextInt();
        cols = input.nextInt();

        int[][] mat1 = new int[rows][cols];
        int[][] mat2 = new int[rows][cols];
        System.out.println("Enter the elements of the first matrix: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat1[i][j] = input.nextInt();
            }
        }
        System.out.println("Enter the elements of the second matrix: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat2[i][j] = input.nextInt();
            }
        }

        matrix_mul(rows, cols, mat1, mat2);
        matrix_sum(rows, cols, mat1, mat2);
    }
}
