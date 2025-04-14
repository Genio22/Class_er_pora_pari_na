/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

import java.util.Arrays;

import java.util.Scanner;

/**
 *
 * @author ahnaf
 */
public class Problem6 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Size: ");
        int size = in.nextInt();
        int[] arr = new int[size];

        System.out.println("Enter the elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = in.nextInt();
        }

        int[] uniqueNumbers = eliminateDuplicates(arr);

        System.out.println("Original array: " + Arrays.toString(arr));
        System.out.println("Array after removing duplicates: " + Arrays.toString(uniqueNumbers));
    }

    public static int[] eliminateDuplicates(int[] list) {
        int n = list.length;
        int[] temp = new int[n];
        int newSize = 0;          // Tracks the size of unique elements

        for (int i = 0; i < n; i++) {
            boolean isDuplicate = false;
            // Check if list[i] already exists in temp
            for (int j = 0; j < newSize; j++) {
                if (list[i] == temp[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            // If not a duplicate, add it to temp
            if (!isDuplicate) {
                temp[newSize++] = list[i];
            }
        }

        // Create the final array of exact size
        int[] uniqueArray = new int[newSize];
        System.arraycopy(temp, 0, uniqueArray, 0, newSize);

        return uniqueArray;
    }
}
