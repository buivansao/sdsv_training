package ex.sds.food;

public class OrderSpec {
    private String foodItemName;
    private String packageItemName;

    public OrderSpec(String foodItemName, String packageItemName) {
        this.foodItemName = foodItemName;
        this.packageItemName = packageItemName;
    }

    public String getFoodItemName() {
        return foodItemName;
    }

    public String getPackageItemName() {
        return packageItemName;
    }

    public void setPackageItemName(String packageItemName) {
        this.packageItemName = packageItemName;
    }

    public void setFoodItemName(String foodItemName) {
        this.foodItemName = foodItemName;
    }
}
