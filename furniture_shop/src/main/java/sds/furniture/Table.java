package sds.furniture;

public class Table implements Furniture {
    private String serialNumber;
    private double initValue, decayFactor;
    private int countShow = 0;

    public Table() {
        super();
    }

    public Table(String serialNumber, double initValue, double decayFactor) {
        setSerialNumber(serialNumber);
        setInitValue(initValue);
        setDecayFactor(decayFactor);
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public double getInitValue() {
        return initValue;
    }

    public void setInitValue(double initValue) {
        this.initValue = initValue;
    }

    public double getDecayFactor() {
        return decayFactor;
    }

    public void setDecayFactor(double decayFactor) {
        this.decayFactor = decayFactor;
    }

    @Override
    public double getPrice() {
        return initValue * (1 - (decayFactor * countShow));
    }

    @Override
    public void show() {
        countShow++;
        System.out.printf("%-20s%-20.1f%-20.1f%-20.1f\n", serialNumber, initValue, decayFactor, getPrice());
    }

    @Override
    public boolean isSold() {
        return true;
    }

    public String toString() {
        return String.format("%-20s%-20.1f%-20.1f%-20.1f\n", serialNumber, initValue, getDecayFactor(), getPrice());
    }
}
