/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

import java.util.Scanner;

/**
 *
 * @author ahnaf
 */
public class Problem4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter triangle base: ");
        int base = input.nextInt();

        System.out.print("Enter triangle height: ");
        int height = input.nextInt();

        System.out.print("Enter triangle color: ");
        String colorTriangle = input.next();

        Shape triangle = new Triangles(colorTriangle, base, height);
        System.out.println(triangle.toString());
        System.out.println("Triangle Area: " + triangle.getArea());

        System.out.println();

        System.out.print("Enter rectangle length: ");
        int length = input.nextInt();

        System.out.print("Enter rectangle width: ");
        int width = input.nextInt();

        System.out.print("Enter rectangle color: ");
        String colorRectangle = input.next();

        Shape rectangle = new Rectangles(colorRectangle, length, width);
        System.out.println(rectangle.toString());
        System.out.println("Rectangle Area: " + rectangle.getArea());

        input.close();
    }
}
