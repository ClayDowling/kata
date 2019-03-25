import org.junit.Before;
import org.junit.Test;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.is;

public class GameTest {

    Game user;

    @Before
    public void setUp(){
        user = new Game();
    }



    @Test
    public void Underpopulation_CellDies () {



        assertThat(user.rules(1,true), is(false));
    }

    @Test
    public void LiveCell_With_TwoOrThree_NeighborsLives(){

        assertThat(user.rules(2,true), is(true));
        assertThat(user.rules(3,true), is(true));
    }

    @Test
    public void LiveCell_MoreThanThree_Dies(){

        assertThat(user.rules(5,true), is(false));
        assertThat(user.rules(4, true), is(false));
    }

    @Test
    public void DeadCell_Exactly_ThreeNeighbors_Lives(){

        assertThat(user.rules(3,false), is(true));
        assertThat(user.rules(2,false), is(false));
    }
}
