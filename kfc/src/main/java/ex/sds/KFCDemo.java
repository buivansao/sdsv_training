package ex.sds;

/**
 * Hello world!
 */
public class KFCDemo {
    public static void main(String[] args) {
        Meal meal1 = Meal.buildMeal("TwoPersonLunch");
        meal1.printMeal();
        Meal meal2 = Meal.buildMeal("FourPersonLunch");
        meal2.printMeal();
    }
}
