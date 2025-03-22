/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab5;

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

        // Array to keep track of visit elements
        boolean[] visit = new boolean[size];

        System.out.println("Element counts: ");

        for (int i = 0; i < size; i++) {
            if (!visit[i]) {
                int count = 1;
                for (int j = i + 1; j < size; j++) {
                    if (arr[i] == arr[j]) {
                        visit[j] = true;
                        arr[i] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] == -1 || arr[i] == arr[i + 1]) {
                arr[i] = arr[i + 1];
            }
        }
        for (Object elem : arr) {
            System.out.println(elem);
        }
    }

}
