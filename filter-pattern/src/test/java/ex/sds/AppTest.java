package ex.sds;

import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class AppTest {
    Company company;

    @Before
    public void init() throws Exception {
        company = new Company();
        company.loadFromFile("employees.txt");
    }

    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue() {
        assertTrue(true);
    }

    @Test
    public void test1() {
        assertTrue(company.getEmployees() != null);
    }

    @Test
    public void testGender() {
        assertTrue(company.getEmployees().get(3).isFemale());
        assertTrue(!company.getEmployees().get(0).isFemale());
    }

    @Test
    public void testNumberOfEmployees() {
        assertTrue(company.getEmployees().size() == 13);
        assertTrue(company.getMaleEmployees().size() == 9);
    }

    @Test
    public void testSalary() {
        assertTrue(company.getEmployees().get(10).salary() == 400);
    }

    @Test
    public void testNumberOfSecurity() {
        assertTrue(company.getSecurityEmployees().size() == 6);
    }
}
