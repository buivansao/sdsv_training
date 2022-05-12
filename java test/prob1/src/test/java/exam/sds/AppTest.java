package exam.sds;

import static org.junit.Assert.assertTrue;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;

import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class AppTest {
    /**
     * Rigorous Test :-)
     *
     * @throws FileNotFoundException
     * @throws UnsupportedEncodingException
     */
    @Test
    public void testMain() throws FileNotFoundException, UnsupportedEncodingException {
        String utf8 = StandardCharsets.UTF_8.name();
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        System.setIn(new FileInputStream("shape.txt"));
        System.setOut(new PrintStream(baos, true, utf8));
        App.main(null);
        String LS = System.lineSeparator();
        String result = "This is a circle with area = 314.0" + System.lineSeparator() + "This is a square with area = 529.0" + LS + "This is a rectangle with area = 55.0" + LS;
        assertTrue(baos.toString(utf8).equals(result));
    }

    @Test
    public void testAreaCalculator() {
        Circle c = new Circle(2);
        assertTrue(AreaCalculator.calcArea(c) - 3.14 * 4 < 0.1);
    }

    @Test
    public void testAreaCalculator1() {
        Square c = new Square(2);
        assertTrue(AreaCalculator.calcArea(c) - 4 < 0.01);
    }

    @Test
    public void testAreaCalculator2() {
        Rectangle c = new Rectangle(2., 3.);
        assertTrue(AreaCalculator.calcArea(c) - 2 * 3 < 0.1);
    }
}
