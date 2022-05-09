package ex.sds.food;

public class Burger extends Dish {
    private String name;
    private double price;

    public Burger() {
        super();
    }

    public Burger(String name, double price) {
        setName(name);
        setPrice(price);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
