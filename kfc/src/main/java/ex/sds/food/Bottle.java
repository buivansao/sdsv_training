package ex.sds.food;

public abstract class Bottle implements IPackage {
    private Beverage food;

    public double price() {
        // TODO Auto-generated method stub
        return 0;
    }

    public boolean canContain(IFoodItem food) {
        // TODO Auto-generated method stub
        return false;
    }

    public void pack(IFoodItem food) throws PackageNotAvailable, FoodAlreadyPacked {
        this.food = (Beverage) food;
    }
}
