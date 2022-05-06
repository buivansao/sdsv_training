package sds.exception;

public class StockEmptyException extends Throwable {
    public StockEmptyException() {
        System.out.println("Out of stock!");
    }
}
