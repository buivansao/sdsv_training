package ex.sds.food;

public abstract class Beverage implements IFoodItem {

    public boolean hasPackage() {
        // TODO Auto-generated method stub
        return false;
    }

    public void use(IPackage pack) throws PackageNotAvailable, FoodAlreadyPacked {
        // TODO Auto-generated method stub

    }

    public double price() {
        // TODO Auto-generated method stub
        return 0;
    }
}
