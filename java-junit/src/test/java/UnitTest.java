import org.junit.Test;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.is;

public class UnitTest {

    @Test
    public void answer_returnsFourtyTwo()
    {
        assertThat(Unit.answer(), is(42));
    }

}