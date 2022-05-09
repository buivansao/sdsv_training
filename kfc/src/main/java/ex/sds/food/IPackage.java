package ex.sds.food;

public interface IPackage extends ISoldItem {
    public boolean canContain(IFoodItem food);

    public void pack(IFoodItem food) throws PackageNotAvailable, FoodAlreadyPacked;
}
