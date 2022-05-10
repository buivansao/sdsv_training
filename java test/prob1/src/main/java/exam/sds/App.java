package exam.sds;

import java.util.Scanner;

class AreaCalculator {
    public static double calcArea(Shape s) {
        switch (s.getClass().getSimpleName()) {
            case "Circle":
                Circle circle = (Circle) s;
                return Math.PI * (circle.getR() * circle.getR());
            case "Rectangle":
                Rectangle rectangle = (Rectangle) s;
                return rectangle.getHeight() * rectangle.getWidth();
            case "Square":
                Square square = (Square) s;
                return square.getWidth() * square.getWidth();
        }
        return 0;
    }
}

class Circle implements Shape {
    private double r;

    public Circle() {
        super();
    }

    public Circle(double r) {
        super();
        this.r = r;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    @Override
    public void print() {
        System.out.println("This is a " + this.getClass().getSimpleName().toLowerCase() + " with area = " + Double.parseDouble(String.valueOf(Math.round(AreaCalculator.calcArea(new Circle(r))))));
    }
}

class Square implements Shape {
    private double width;

    public Square() {
        super();
    }

    public Square(double width) {
        super();
        this.width = width;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    @Override
    public void print() {
        System.out.println("This is a " + this.getClass().getSimpleName().toLowerCase() + " with area = " + AreaCalculator.calcArea(new Square(width)));
    }
}

class Rectangle implements Shape {
    private double width, height;

    public Rectangle() {
        super();
    }

    public Rectangle(double width, double height) {
        super();
        this.width = width;
        this.height = height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public void print() {
        System.out.println("This is a " + this.getClass().getSimpleName().toLowerCase() + " with area = " + AreaCalculator.calcArea(new Rectangle(width, height)));
    }
}

interface Shape {
    public void print();
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            String[] line = sc.nextLine().split(" ");
            Shape shape = null;

            if (line[0].equals("Circle")) {
                shape = new Circle(Double.parseDouble(line[1]));
            } else if (line[0].equals("Square")) {
                shape = new Square(Double.parseDouble(line[1]));
            } else {
                shape = new Rectangle(Double.parseDouble(line[1]), Double.parseDouble(line[2]));
            }

            shape.print();
        }
    }
}
