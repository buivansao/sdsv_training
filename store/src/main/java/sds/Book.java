package sds;

public class Book extends Item {
    public Book(String name, double price) {
        super(name, price);
    }

    @Override
    public double getPrice() {
        return getValue() * 1.2;
    }
}
