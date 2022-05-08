package sds;

public class Laptop extends Item {
    public Laptop(String name, double price) {
        super(name, price);
    }

    @Override
    public double getPrice() {
        return getValue() * 1.5;
    }
}
