package sds;

import java.util.HashMap;
import java.util.Scanner;

public class DistinctCounterNumber {
    private int[] arrNum;
    private String line;
    private HashMap<Integer, Integer> hashNum = new HashMap<Integer, Integer>();

    public DistinctCounterNumber() {
        super();
    }

    public DistinctCounterNumber(int[] arrNum) {
        setArrNum(arrNum);
        for (int i : arrNum) {
            if (!hashNum.containsKey(i)) {
                hashNum.put(i, i);
            }
        }
    }

    public DistinctCounterNumber(String line) {
        String[] str = line.split("\\W+");
        for (String s : str) {
            int k = Integer.parseInt(s);
            if (!hashNum.containsKey(k)) {
                hashNum.put(k, k);
            }
        }
    }

    public int[] getArrNum() {
        return arrNum;
    }

    public void setArrNum(int[] arrNum) {
        this.arrNum = arrNum;
    }

    public String getLine() {
        return line;
    }

    public void setLine(String line) {
        this.line = line;
    }

    public void readArray() {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter number: ");
            int num = scanner.nextInt();
            if (!hashNum.containsKey(num)) {
                hashNum.put(num, num);
            }
        }
    }

    public int countDistinct() {
        return hashNum.size();
    }
}
