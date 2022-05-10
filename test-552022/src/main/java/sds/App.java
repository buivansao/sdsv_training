package sds;

public class App {
    public static void main(String[] args) {
        RandomStringGenerator randomStringGenerator1 = new RandomStringGenerator(0, 20);
        System.out.println(randomStringGenerator1.generate());

        RandomStringGenerator randomStringGenerator2 = new RandomStringGenerator(0, 20);
        System.out.println(randomStringGenerator2.generate(5));

        RandomStringGenerator randomStringGenerator3 = new RandomStringGenerator(0, 20);
        System.out.println(randomStringGenerator3.generate(5, 5));


        System.exit(1);

        System.out.println("Array");
        DistinctCounterNumber array = new DistinctCounterNumber(new int[]{1, 2, 3, 1, 2});
        System.out.println("Distinct counter: " + array.countDistinct());

        System.out.println("--------------");

        System.out.println("String");
        DistinctCounterNumber string = new DistinctCounterNumber("1;2;3;1;2");
        System.out.println("Distinct counter: " + string.countDistinct());

        System.out.println("--------------");

        System.out.println("Input");
        DistinctCounterNumber input = new DistinctCounterNumber();
        input.readArray();
        System.out.println("Distinct counter: " + input.countDistinct());
    }
}
