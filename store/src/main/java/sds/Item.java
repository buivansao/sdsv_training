package sds;

public abstract class Item {
    private String name;
    private double price, value;

    public Item(String name, double value) {
        super();
        setName(name);
        setValue(value);
    }

    public String getName() {
        return name;
    };
    public double getValue() {
        return value;
    }

    public abstract double getPrice();

    public void setName(String name) {
        this.name = name;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public void showInfo() {
        System.out.printf("%-20s%-20.2f%-20.2f%-20.2f\n", getName(), getValue(), getPrice(), getPrice() - getValue());
    }
}
