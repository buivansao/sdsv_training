package sds;

public class ProxyPatternDemo {
    public static void main(String[] args) {
        System.out.println("Proxy Pattern Demo");
        System.out.println("----");
        Image image = new ProxyImage("test.png");
        image.display();

        System.out.println("----");
        new ProxyImage("abc.png").display();
    }
}
