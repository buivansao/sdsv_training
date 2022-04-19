package sdsv;

public class Component {
    private String type, serialNumber;
    private double price;

    public Component(String type, String serialNumber, double price) {
        this.setType(type);
        this.setSerialNumber(serialNumber);
        this.setPrice(price);
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getType() {
        return type;
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public double getPrice() {
        return price;
    }

    public void show() {
        System.out.printf("%-20s%-20s%-20.1f\n", type, serialNumber, price);
    }
}
