package sds;

public class ProxyImage implements Image {
    private String fileName;
    private RealImage realImage;

    public ProxyImage(String fileName) {
        realImage = new RealImage(fileName);
    }

    @Override
    public void display() {
        realImage.display();
    }
}
