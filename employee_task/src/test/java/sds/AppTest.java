package sds;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

import org.junit.Before;
import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class AppTest {
    private ByteArrayOutputStream baos;

    @Before
    public void init() throws FileNotFoundException {
        baos = new ByteArrayOutputStream();
        System.setOut(new PrintStream(baos));
    }

    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue() {
        assertTrue(true);
    }

    @Test
    public void test1() throws Exception {
        System.setIn(Files.newInputStream(Paths.get("input1.txt")));
        App.main(null);
        assertEquals("BEST:Bob-5000.0-1\r\nWORST:Peter-2130.0-3\r\n", baos.toString(StandardCharsets.UTF_8.name()));
    }

    @Test
    public void test2() throws Exception {
        System.setIn(Files.newInputStream(Paths.get("input2.txt")));
        App.main(null);
        assertEquals("BEST:Peter-2130.0-3\r\nWORST:Peter-2130.0-3\r\n", baos.toString(StandardCharsets.UTF_8.name()));
    }

    @Test
    public void test3() throws Exception {
        System.setIn(Files.newInputStream(Paths.get("input3.txt")));
        App.main(null);
        assertEquals("BEST:Bob-5000.0-1\r\nWORST:Susan-10.0-2\r\n", baos.toString(StandardCharsets.UTF_8.name()));
    }

    @Test
    public void test4() throws Exception {
        System.setIn(Files.newInputStream(Paths.get("input.txt")));
        App.main(null);
        assertEquals("BEST:Bob-5000.0-1\r\nWORST:Mary-0.0-0\r\n", baos.toString(StandardCharsets.UTF_8.name()));
    }
}
