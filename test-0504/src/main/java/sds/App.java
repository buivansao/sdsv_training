package sds;


import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) throws IOException {
//        List<Double> arrDouble = new ArrayList<Double>();
//        for (int i = 0; i < 20; i++) {
//            arrDouble.add(i * 3.0);
//        }
//
//        Double[] arr = arrDouble.toArray(new Double[0]);
//
//        print(arr, " ");
//        print(multipleDouble(arr, 2), " ");
//        print(between(arr, 30, 70), " ");

        Company c = new Company("SDS");
        c.addEmployee(new Employee(1, "Star1", "Dev1"));
        c.addEmployee(new Employee(2, "Star2", "Dev2"));
//        c.saveToFile("data.txt");
        c.loadFromFile("data.txt");
        System.out.println(c.hasEmployee(1));
        System.out.println(c.getEmployee(1));
    }

    private static Double[] multipleDouble(Double[] arrayDouble, double factor) {
        List<Double> tmpArr = new ArrayList<Double>();
        for (Double v : arrayDouble) {
            tmpArr.add(v * factor);
        }

        return tmpArr.toArray(new Double[0]);
    }

    private static Double[] between(Double[] arrayDouble, double upper, double lower) {
        List<Double> tmpArr = new ArrayList<Double>();
        for (Double v : arrayDouble) {
            if (v >= upper && v <= lower) {
                tmpArr.add(v);
            }
        }

        return tmpArr.toArray(new Double[0]);
    }

    private static void print(Object[] arrayDouble, String delim) {
        StringBuilder stringBuilder = new StringBuilder();
        for (Object v : arrayDouble) {
            stringBuilder.append(v).append(delim);
        }

        System.out.println(stringBuilder);
    }
}
