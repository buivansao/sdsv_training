package sdsv;

public class App {
    public static void main(String[] args) {
        System.out.println("Computer Store");

        Computer computer = new Computer("Logitech");
        for (int i = 0; i < 3; i++) {
            Component com = new Component("Mouse" + i, "a" + i, i + 100);
            computer.addComponent(com);
        }
        computer.show();
        System.out.println("Total price of " + computer.getModel() + " is: " + computer.calcPrice());
    }
}
