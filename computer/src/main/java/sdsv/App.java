package sdsv;

import java.util.ArrayList;
import java.util.List;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        System.out.println("\nHello my friends ^_^\n");

        List<Computer> computers = new ArrayList<>();

        for (int i = 0; i < 2; i++) {
            computers.add(new Computer("computer-" + i));
        }
        String[] components = new String[]{"monitor", "cpu", "mouse", "keyboard"};

        for (Computer computer : computers) {
            for (String com : components) {
                for (int i = 0; i < 2; i++) {
                    Component component = new Component();
                    component.setSerialNumber(com + "-" + i);
                    component.setPrice(1000 * (i + 1));

                    computer.addComponent(component);
                }
            }
        }

        for (Computer computer : computers) {
            System.out.println("Computer's serial number: " + computer.getSerialNumber());
            System.out.printf("%-20s%-20s\n", "Serial", "Price");
            computer.showConfig();
            System.out.println("Total price of " + computer.getSerialNumber() + " is: " + computer.calcPrice() + "\n");
        }

        System.out.println("\nGet components:");
        for (Computer computer : computers) {
            String com = computer.getComponent("cpu-0");
            if (!com.isEmpty()) {
                System.out.print(computer.getSerialNumber() + ": " + com);
            } else {
                System.out.println(computer.getSerialNumber() + " not have component with serial cpu-0");
            }
        }

        System.out.println("\nRemove component");
        for (Computer computer : computers) {
            if (computer.removeComponent("mouse-0")) {
                System.out.print(computer.getSerialNumber() + ": Removed component with serial number 'mouse-0'\n");
            }

            System.out.println("After remove component\n");
            System.out.println("Computer's serial number: " + computer.getSerialNumber());
            System.out.printf("%-20s%-20s\n", "Serial", "Price");
            computer.showConfig();
            System.out.println("Total price of " + computer.getSerialNumber() + " is: " + computer.calcPrice() + "\n");
        }
    }
}
