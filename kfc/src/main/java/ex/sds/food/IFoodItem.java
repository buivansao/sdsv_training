package ex.sds.food;

public interface IFoodItem extends ISoldItem {
    public boolean hasPackage();

    public void use(IPackage pack) throws PackageNotAvailable, FoodAlreadyPacked;
}
