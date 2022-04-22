package sds;

import java.util.ArrayList;
import java.util.List;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println("\nHello my friends ^_^\n");

        System.out.println("***1. Add Store\n");
        List<Store> stores = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            stores.add(new Store("Store " + i));
        }

        System.out.println("***2. Add Item\n");
        for (Store store : stores) {
            for (int i = 0; i < 2; i++) {
                store.addItem(new Book("English " + i, 1000));
                store.addItem(new Laptop("Dell XPS " + i, 2000));
            }
        }

        System.out.println("\n***3. List Items");
        for (Store store : stores) {
            store.listItems();
            System.out.println("Total money: " + store.totalMoney() + "\n");
            System.out.println("-------------------------------------------");
        }

        System.out.println("\n***4. Sell Item\n");
        for (Store store : stores) {
            if (store.sell("English 1")) {
                System.out.println("Sell item English 1 of store " + store.getName());
                System.out.println("Total money: " + store.getTotalMoney() + "\n");
            }
        }
    }
}
