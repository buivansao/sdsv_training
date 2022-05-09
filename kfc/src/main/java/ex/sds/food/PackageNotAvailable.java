package ex.sds.food;

public class PackageNotAvailable extends Exception {
    public PackageNotAvailable() {
        System.out.println("Package is not available!");
    }
}
