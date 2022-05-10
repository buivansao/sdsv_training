package sds;

public class ShapeFactory {
    public Shape getShape(String shapeName) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
        return (Shape) Class.forName(this.getClass().getPackage().getName() + "." + shapeName).newInstance();
    }
}
