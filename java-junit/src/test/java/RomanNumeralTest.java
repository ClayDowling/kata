import org.junit.Test;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.is;
import static org.junit.Assert.assertEquals;

public class RomanNumeralTest {

    @Test
    public void one_return_I() {
        assertEquals("I", RomanNumeral.toRoman(1));
    }

    @Test
    public void five_returns_V() {
        assertEquals("V", RomanNumeral.toRoman(5));
    }

    @Test
    public void ten_returns_X() {
        assertEquals("X", RomanNumeral.toRoman(10));
    }

}