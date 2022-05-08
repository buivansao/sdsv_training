package sdsv;

import java.util.ArrayList;
import java.util.List;

public class Computer {
    private String model;
    private final List<Component> components;

    public Computer(String model) {
        this.components = new ArrayList<>();
        this.setModel(model);
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getModel() {
        return model;
    }

    public void show() {
        System.out.println("Model: " + model);
        System.out.printf("%-20s%-20s%-20s\n", "Type", "Serial", "Price");
        for (Component com : components) {
            com.show();
        }
    }

    public void addComponent(Component com) {
        this.components.add(com);
    }

    public double calcPrice() {
        int price = 0;
        for (Component com : components) {
            price += com.getPrice();
        }

        return price;
    }
}
