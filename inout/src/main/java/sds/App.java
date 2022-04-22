package sds;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) throws FileNotFoundException {
        System.out.println( "Hello World!" );

        // Demo read file line by line
        BufferedReader reader = new BufferedReader(new FileReader("data.txt"));
    }
}
