/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab4;

/**
 *Write a method that returns a new array by eliminating the duplicate values in the array using the following method header:
 */
public class Problem6 {
    public static void main(String[] agrs){
        int size;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of entry of array: ");
        size = input.nextInt();
        int[] mat1 = new int[size];
        System.out.println("Enter the elements of the matrix: ");
        for (int i = 0; i < size; i++) {
            mat1[i] = input.nextInt();
        }
        elem(size,mat1);
    }
    public static void elem(int size, int[] mat1){
        int[] mat2 = new int [size];
        int n=0;
        boolean a = true;
        for (int i = 0; i<size;i++){
            a = false;
            for (int j=0;j<size; j++){
                if (mat1[i]==mat2[j]){
                    a=true;
                    break;
                }
            }
            if (!a){
                mat2[n]= mat1[i];
                n++;
                //a=false;
            }
        }
        for (int e:mat2){
            if (e!=0){
            System.out.print(e+" ");
        }}
    }
