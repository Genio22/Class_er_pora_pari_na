package com.mycompany.lab3;

import java.util.Scanner;

/**
 * Find the odd and even numbers in an array and save them in two different
 * arrays.
 */
public class Problem21 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Size: ");
        int b = in.nextInt();
        int[] a = new int[b];
        int[] c = new int[b];
        int[] d = new int[b];
        int ecount = 0, ocount = 0;
        for (int i = 0; i < b; i++) {
            a[i] = (int) (Math.random() * 10);
            if (a[i] % 2 == 0 && a[i] != 0) {
                c[i] = a[i];
                ecount++;
            } else {
                d[i] = a[i];
                ocount++;
            }
        }
        System.out.println("C array");
        for (int i = 0; i < ecount; i++) {
            if (c[i] != 0) {
                System.out.println(c[i]);
            }
        }
        System.out.println("D array");
        for (int i = 0; i < ocount; i++) {
            if (d[i] != 0) {
                System.out.println(d[i]);
            }
        }

    }

}
