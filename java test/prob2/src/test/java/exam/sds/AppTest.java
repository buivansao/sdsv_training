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
public class AppTest 
{
    /**
     * Rigorous Test :-)
     * @throws UnsupportedEncodingException
     * @throws FileNotFoundException
     */
    @Test
    public void testMain() throws UnsupportedEncodingException, FileNotFoundException, ListFullException {
        String utf8 = StandardCharsets.UTF_8.name();
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        System.setIn(new FileInputStream("todo.txt"));
        System.setOut(new PrintStream(baos, true, utf8));
        App.main(null);
        String LS = System.lineSeparator();
        String result = "3 1 Study" + System.lineSeparator();
        assertTrue( baos.toString(utf8).equals(result) );
    }
}
