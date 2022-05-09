package ex.sds.food;

public class LemonJuice extends Beverage {
    private String name;
    private double price;

    public LemonJuice() {
        super();
    }

    public LemonJuice(String name, double price) {
        this.name = name;
        this.price = price;
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
