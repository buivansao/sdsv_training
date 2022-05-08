package sds;

import java.util.ArrayList;
import java.util.List;

public class Store {
    private String name;
    private double totalMoney = 0;
    private List<Item> items = new ArrayList<>();

    public Store(String name) {
        super();
        setName(name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getTotalMoney() {
        return totalMoney;
    }

    public void addItem(Item item) {
        items.add(item);
        System.out.println("Added item " + item.getName() + " successfully!");
    }

    public Item getItem(String name) {
        for (Item item : items) {
            if (item.getName().equals(name)) {
                return item;
            }
        }

        return null;
    }

    public void listItems() {
        System.out.println("Store name: " + name + "\n");
        System.out.printf("%-20s%-20s%-20s%-20s\n", "Item name", "Price", "Value", "Sub Money");
        for (Item item : items) {
            item.showInfo();
        }
        System.out.println("");
    }

    public double totalMoney() {
        for (Item item : items) {
            totalMoney += item.getValue();
        }

        return totalMoney;
    }

    public boolean sell(String name) {
        for (Item item : items) {
            if (item.getName().equals(name)) {
                items.remove(item);
                totalMoney += item.getPrice() - item.getValue();
                return true;
            }
        }

        return false;
    }
}
