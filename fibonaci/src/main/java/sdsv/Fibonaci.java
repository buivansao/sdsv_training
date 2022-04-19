package sdsv;

public class Fibonaci {
    private int fibonaciNumber;
    private HashMapResultCache resultCache;

    public Fibonaci(int number) {
        resultCache = new HashMapResultCache();
        fibonaciNumber = number;
    }

    public int calFibonaci(int fibNum) {
        if (fibNum == 0 || fibNum == 1) {
            resultCache.save(fibNum, fibNum);
            return fibNum;
        } else {
            if (resultCache.get(fibNum) != -1) {
                return resultCache.get(fibNum);
            } else {
                int result = calFibonaci(fibNum - 1) + calFibonaci(fibNum - 2);
                resultCache.save(fibNum, result);

                return result;
            }
        }
    }
}
