package com.mycompany.lab6;

abstract class Shape {

    protected String color;

    public Shape(String color) {
        this.color = color;
    }

    public abstract double getArea();

    public abstract String toString();
}

class Rectangles extends Shape {

    private int length;
    private int width;

    public Rectangles(String color, int length, int width) {
        super(color);
        this.length = length;
        this.width = width;
    }

    @Override
    public double getArea() {
        return length * width;
    }

    @Override
    public String toString() {
        return "Rectangles [color=" + color + ", length=" + length + ", width=" + width + "]";
    }
}

class Triangles extends Shape {

    private int base;
    private int height;

    public Triangles(String color, int base, int height) {
        super(color);
        this.base = base;
        this.height = height;
    }

    @Override
    public double getArea() {
        return 0.5 * base * height;
    }

    @Override
    public String toString() {
        return "Triangles [color=" + color + ", base=" + base + ", height=" + height + "]";
    }
}
