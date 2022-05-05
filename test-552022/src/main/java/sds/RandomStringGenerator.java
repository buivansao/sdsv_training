package sds;

import java.util.Random;

public class RandomStringGenerator {
    private int mode, nLength;
    private String[] lower = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    private String[] upper = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    private int[] numeric = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    private Random random;
    private StringBuilder stringBuilder;
    private int countChar = 0, countNum = 0;

    public RandomStringGenerator(int mode, int nLength) {
        this.mode = mode;
        this.nLength = nLength;
        random = new Random();
        stringBuilder = new StringBuilder();
    }

    public String generate() {
        mode = 0;
        for (int i = 0; i < nLength; i++) {
            stringBuilder.append(lower[getRandomNumber()]);
        }
        return stringBuilder.toString();
    }

    public String generate(int nUpper) {
        mode = 1;
        for (int i = 0; i < nLength; i++) {
            if (getRandomMode(2) == mode) {
                countChar++;
                if (countChar <= nUpper) {
                    stringBuilder.append(upper[getRandomNumber()]);
                } else {
                    stringBuilder.append(lower[getRandomNumber()]);
                }
            } else {
                stringBuilder.append(lower[getRandomNumber()]);
            }
        }

        return stringBuilder.toString();
    }

    public String generate(int nUpper, int nNumeric) {
        mode = 2;
        for (int i = 0; i < nLength; i++) {
            if (getRandomMode(3) == 1) {
                countChar++;
                if (countChar <= nUpper) {
                    stringBuilder.append(upper[getRandomNumber()]);
                } else {
                    stringBuilder.append(lower[getRandomNumber()]);
                }
            } else {
                stringBuilder.append(lower[getRandomNumber()]);
            }
        }

        return stringBuilder.toString();
    }

    private int getRandomNumber() {
        if (mode == 0 || mode == 1) {
            return random.nextInt(lower.length);
        }
        return random.nextInt(numeric.length);
    }

    private int getRandomMode(int maxNum) {
        return random.nextInt(2);
    }
}
