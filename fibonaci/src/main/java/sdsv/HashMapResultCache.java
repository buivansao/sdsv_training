package sdsv;

import java.util.HashMap;

public class HashMapResultCache implements ResultCache {
    private HashMap<Integer, Integer> hashResult = new HashMap<Integer, Integer>();


    @Override
    public void save(int n, int result) {
        hashResult.put(n, result);
    }

    @Override
    public int get(int n) {
        if (hashResult.containsKey(n)) {
            return hashResult.get(n);
        } else {
            return -1;
        }
    }
}
