/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab3;

//import java.util.*;
import java.util.Scanner;

/*
 *To find if a number is palindrome or not.
 *Sample input:		    output:
 *1234			    not palindrome
 *121			        palindrome
 *111			        palindrome
 *12221			        palindrome
 *2331			    not palindrome
 */
// version 2
public class Problem8 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a number to check palindrome: ");
        int ori = in.nextInt();
        int newr = ori;
        int mul = 0;
        while (ori != 0) {
            mul = mul * 10 + (ori % 10);
            ori /= 10;
        }
        if (newr == mul) {
            System.out.println("It's a palindrome");
        } else {
            System.out.println("It's not a palindrome");
        }
        // debug
        //System.out.println(mul);
    }
}

// version 1
/*public class Problem8 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number to check: ");
        int a = in.nextInt();
        int acount = 0;
        int c = a;
        while (c != 0) {
            c /= 10;
            acount++;
        }

        int b = 0;
        int[] d = new int[acount];
        while (a != 0) {
            d[b] = a % 10;
            a /= 10;
            b++;
        }
        int idx = -1;
        int count = 0;
        for (int i = 0; i < (acount / 2) + 1; i++) {
            if (d[i] == d[--acount]) {
                count++;
                if (count == (acount / 2)) {
                    idx = 1;
                }
            }
        }
        if (idx == 1) {
            System.out.println("It's a palindrome");
        } else {
            System.out.println("It's not a palindrome");
        }

        for (int e : d) {
            System.out.print(e);
        }
    }
}
 */
