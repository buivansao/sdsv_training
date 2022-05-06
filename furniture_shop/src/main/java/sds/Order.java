package sds;

import sds.furniture.Furniture;

import java.util.ArrayList;
import java.util.List;

public class Order {
    private Furniture furniture;

    public Order(Furniture furniture) {
        setFurniture(furniture);
    }

    public Furniture getFurniture() {
        return furniture;
    }

    public void setFurniture(Furniture furniture) {
        this.furniture = furniture;
    }

    public Furniture soldItem() {
        return getFurniture();
    }

    @Override
    public String toString() {
        return furniture.toString();
    }
}
