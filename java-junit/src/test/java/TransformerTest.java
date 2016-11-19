import org.junit.Test;

import static org.hamcrest.Matchers.is;
import static org.junit.Assert.*;

/**
 * Created by clay on 11/18/16.
 */
public class TransformerTest {

    @Test
    public void infixToRpn_giveAPlusB_givesABPlus()
    {
        assertThat(Transformer.infix_to_rpn("a+b"), is("ab+"));
    }

    @Test
    public void infixToRpn_givenATimesB_givesABTimes()
    {
        assertThat(Transformer.infix_to_rpn("a*b"), is("ab*"));
    }

}