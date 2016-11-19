/**
 * Created by clay on 11/18/16.
 */
public class AstNode {

    public char operator;
    public AstNode left;
    public AstNode right;

    public AstNode()
    {
        operator = ' ';
        left = null;
        right = null;
    }

    public AstNode(char x)
    {
        operator = x;
        left = null;
        right = null;
    }
}
