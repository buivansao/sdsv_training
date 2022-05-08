package sdsv;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        int fibNum = 60;

        Fibonaci fibonaciObj = new Fibonaci(fibNum);
        System.out.println("Fibonaci of " + fibNum + "th is: " + fibonaciObj.calFibonaci(fibNum));
    }
}
