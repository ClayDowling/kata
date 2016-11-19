import org.junit.Test;

import static org.hamcrest.Matchers.is;
import static org.junit.Assert.*;

/**
 * Created by clay on 11/19/16.
 */
public class AstParserTest {

    @Test
    public void parseInfix_givenAPlusB_yieldsTreeWithABasChildrenOfPlus()
    {
        AstNode operator;
        AstNode left;
        AstNode right;

        operator = AstParser.parse_infix("a+b");
        left = operator.left;
        right = operator.right;

        assertThat(operator.operator, is('+'));
        assertThat(left.operator, is('a'));
        assertThat(right.operator, is('b'));
    }

    @Test
    public void parseInfix_givenAPlusBTimesC_yieldsTreeWithBCasChildrenOfTimesAandBtimesCAsChildOfPlus()
    {
        AstNode opPlus;
        AstNode opA;
        AstNode opTimes;
        AstNode opB;
        AstNode opC;

        opPlus = AstParser.parse_infix("a+b*c");

        assertThat(opPlus.operator, is('+'));
        opA = opPlus.left;
        assertThat(opA.operator, is('a'));
        opTimes = opPlus.right;
        assertThat(opTimes.operator, is('*'));
        opB = opTimes.left;
        assertThat(opB.operator, is('b'));
        opC = opTimes.right;
        assertThat(opC.operator, is('c'));
    }
}