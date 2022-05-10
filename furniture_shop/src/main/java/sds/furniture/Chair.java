package sds.furniture;

import sds.furniture.Furniture;

public class Chair implements Furniture {
    private String serialNumber;
    private double initValue, decayConstant;
    private int countShow = 0;

    public Chair() {
        super();
    }

    public Chair(String serialNumber, double initValue, double decayConstant) {
        setSerialNumber(serialNumber);
        setInitValue(initValue);
        setDecayConstant(decayConstant);
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

    public double getDecayConstant() {
        return decayConstant;
    }

    public void setDecayConstant(double decayConstant) {
        this.decayConstant = decayConstant;
    }

    @Override
    public double getPrice() {
        return initValue - (decayConstant * countShow);
    }

    @Override
    public void show() {
        countShow++;
        System.out.printf("%-20s%-20.1f%-20.1f%-20.1f\n", serialNumber, initValue, decayConstant, getPrice());
    }

    @Override
    public boolean isSold() {
        return false;
    }

    public String toString() {
        return String.format("%-20s%-20.1f%-20.1f%-20.1f\n", serialNumber, initValue, getDecayConstant(), getPrice());
    }
}
