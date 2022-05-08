package sdsv;

public class Component {
    private String serialNumber;
    private double price;

    public Component(String serialNumber, double price) {
        super();
        this.setSerialNumber(serialNumber);
        this.setPrice((float) price);
    }

    public Component() {
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public float getPrice() {
        return (float) price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public void showSpecification() {
        System.out.printf("%-20s%-20.2f\n", serialNumber, price);
    }
}
