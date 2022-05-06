package sds;

import sds.exception.NoMoreSpaceException;
import sds.exception.StockEmptyException;
import sds.furniture.Furniture;
import sds.furniture.FurnitureFactory;

public class App {
    public static void main(String[] args) throws NoMoreSpaceException, StockEmptyException {
        FurnitureShop furnitureShop = new FurnitureShop(10);
        FurnitureFactory furnitureFactory = new FurnitureFactory();

        for (int i = 0; i < 5; i++) {
            furnitureShop.stock(furnitureFactory.createChair("chair-" + i, 1000, 10 * (i + 1)));
            furnitureShop.stock(furnitureFactory.createTable("table-" + i, 5000, 0.05));
        }

        // Each furniture showed once time
        System.out.printf("%-20s%-20s%-20s%-20s\n", "Serial", "Init value", "Decay", "Price");
        for (Furniture f : furnitureShop.getItems()) {
            f.show();
        }

//        List<Furniture> fChairs = furnitureShop.getAvailableChairs(furnitureShop.getItems());
//        List<Furniture> fTables = furnitureShop.getAvailableTables(furnitureShop.getItems());

        // Sell one chair and one table
        furnitureShop.sell("Chair");
        furnitureShop.sell("Table");

        // Show order
        System.out.println("------------------------\n");
        System.out.println("Show orders:\n");
        System.out.printf("%-20s%-20s%-20s%-20s\n", "Serial", "Init value", "Decay", "Price");
        for (Order order : furnitureShop.getOrders()){
            System.out.print(order.toString());
        }

        // Show Revenue
        System.out.println("------------------------\n");
        System.out.println("Revenue: " + furnitureShop.revenue());
    }
}
