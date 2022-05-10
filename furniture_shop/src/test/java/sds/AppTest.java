package sds;

import org.junit.Before;
import org.junit.Test;
import sds.exception.NoMoreSpaceException;
import sds.exception.StockEmptyException;
import sds.furniture.FurnitureFactory;

import static org.junit.Assert.*;

/**
 * Unit test for simple App.
 */
public class AppTest {
    private FurnitureShop furnitureShop;
    private FurnitureFactory furnitureFactory;

    @Before
    public void init() throws NoMoreSpaceException {
        furnitureShop = new FurnitureShop(10);
        furnitureFactory = new FurnitureFactory();
        for (int i = 0; i < 5; i++) {
            furnitureShop.stock(furnitureFactory.createChair("chair-" + i, 1000, 10 * (i + 1)));
            furnitureShop.stock(furnitureFactory.createTable("table-" + i, 5000, 0.05));
        }
    }

    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue() {
        assertTrue(true);
    }

    @Test
    public void testTotalItem() {
        assertTrue(furnitureShop.getItems().size() == 10);
        assertTrue(furnitureShop.getAvailableChairs().size() == 5);
        assertTrue(furnitureShop.getAvailableTables().size() == 5);
    }

    @Test
    public void testSellItem() throws StockEmptyException {
        furnitureShop.sell("Chair");
        furnitureShop.sell("Table");
        assertTrue(furnitureShop.getItems().size() == 8);
    }
}
