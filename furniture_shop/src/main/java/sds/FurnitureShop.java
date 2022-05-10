package sds;

import sds.exception.NoMoreSpaceException;
import sds.exception.StockEmptyException;
import sds.furniture.Furniture;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class FurnitureShop {
    private int capacity;
    private List<Furniture> items;
    private List<Order> orders;
    private Random random;

    public FurnitureShop() {
        super();
    }

    public FurnitureShop(int capacity) {
        super();
        setCapacity(capacity);
        random = new Random();
        items = new ArrayList<Furniture>();
        orders = new ArrayList<Order>();
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public List<Furniture> getItems() {
        return items;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public void stock(Furniture furniture) throws NoMoreSpaceException {
        if (items.size() >= getCapacity()) {
            throw new NoMoreSpaceException();
        } else {
            items.add(furniture);
        }
    }

    public void sell(String furnitureType) throws StockEmptyException {
        if (furnitureType.equals("Chair")) {
            soldFurniture(getAvailableChairs());
        } else if (furnitureType.equals("Table")) {
            soldFurniture(getAvailableTables());
        } else {
            throw new StockEmptyException();
        }
    }

    public List<Furniture> getAvailableChairs() {
        List<Furniture> chairs = new ArrayList<Furniture>();
        for (Furniture furniture : items) {
            if (furniture.getClass().getName().contains("Chair")) {
                chairs.add(furniture);
            }
        }

        return chairs;
    }

    public List<Furniture> getAvailableTables() {
        List<Furniture> tables = new ArrayList<Furniture>();
        for (Furniture furniture : items) {
            if (furniture.getClass().getName().contains("Table")) {
                tables.add(furniture);
            }
        }

        return tables;
    }

    public double revenue() {
        double revenue = 0;
        for (Order order : orders) {
            Furniture furniture = order.getFurniture();
            revenue += (furniture.getInitValue() - furniture.getPrice());
        }

        return revenue;
    }

    private void soldFurniture(List<Furniture> furnitures) throws StockEmptyException {
        if (furnitures.size() > 0) {
            Furniture furniture = furnitures.get(getRandomFurnitureIndex(furnitures.size()));
            Order order = new Order(furniture);
            order.soldItem();
            orders.add(order);
            items.remove(furniture);
        } else {
            throw new StockEmptyException();
        }
    }

    private int getRandomFurnitureIndex(int maxLength) {
        return random.nextInt(maxLength);
    }
}
