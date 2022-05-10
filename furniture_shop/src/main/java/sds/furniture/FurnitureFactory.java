package sds.furniture;

public class FurnitureFactory {
    public Table createTable() {
        return new Table();
    }
    
    public Table createTable(String sn, double initialValue, double decayFactor) {
        return new Table(sn, initialValue, decayFactor);
    }

    public Chair createChair() {
        return new Chair();
    }

    public Chair createChair(String sn, double initialValue, double decayConstant) {
        return new Chair(sn, initialValue, decayConstant);
    }
}
