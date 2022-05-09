package ex.sds.food;

public class Coke extends Beverage {
    private String name;
    private double price;

    public Coke() {
        super();
    }

    public Coke(String name, double price) {
        setName(name);
        setPrice(price);
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
