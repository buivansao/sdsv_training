package sds;

import java.lang.reflect.InvocationTargetException;

public class FactoryPatternDemo {
    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        System.out.println("-----");
        ShapeMaker shapeMaker = new ShapeMaker();
        shapeMaker.drawCircle();
        shapeMaker.drawRectangle();
        shapeMaker.drawSquare();

        System.out.println("-----");
        ShapeFactory shapeFactory = new ShapeFactory();
        shapeFactory.getShape("Rectangle").draw();
        shapeFactory.getShape("Square").draw();
        shapeFactory.getShape("Circle").draw();
    }
}
