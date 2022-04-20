package sdsv;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Computer {
    private String serialNumber;
    private List<Component> components = new ArrayList<>();

    public Computer(String serialNumber) {
        super();
        this.setSerialNumber(serialNumber);
    }

    public Computer() {
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }

    public void addComponent(Component com) {
        components.add(com);
    }

    public String getComponent(String serialNumber) {
        StringBuilder str = new StringBuilder();
        for (Component component : components) {
            if (component.getSerialNumber().equals(serialNumber)) {
                str.append(component.getSerialNumber()).append(" - ").append(component.getPrice()).append("\n");
            }
        }
        return str.toString();
    }

    public boolean removeComponent(String serialNumber) {
        for (Component component : components) {
            if (component.getSerialNumber().equals(serialNumber)) {
                components.remove(component);
                return true;
            }
        }
        return false;
    }

    public void showConfig() {
        for (Component com : components) {
            com.showSpecification();
        }
    }

    public float calcPrice() {
        float totalPrice = 0;
        for (Component component : components) {
            totalPrice += component.getPrice();
        }

        return totalPrice;
    }
}
