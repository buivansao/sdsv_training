package sdsv;

public interface ResultCache {
    public void save(int n, int result);

    public int get(int n);
}
