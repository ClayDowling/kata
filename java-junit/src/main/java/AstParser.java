import java.util.Stack;

/**
 * Created by clay on 11/19/16.
 */
public class AstParser {

    public static AstNode parse_infix(String infix)
    {
        Stack<AstNode> opstack = new Stack<AstNode>();
        Stack<AstNode> valuestack = new Stack<AstNode>();
        int i;
        char x;
        AstNode top = null;
        AstNode current;


        for(i=0; i < infix.length(); ++i) {
            x = infix.charAt(i);

            current = new AstNode(x);

            switch(current.operator) {
                case '^':
                case '/':
                case '*':
                case '-':
                case '+':
                    opstack.push(current);
                    break;
                default:
                    valuestack.push(current);
                    break;
            }
        }

        while(!opstack.empty()) {
            current = opstack.pop();
            top = current;
            current.right = valuestack.pop();
            current.left = valuestack.pop();
            valuestack.push(current);
        }

        return top;
    }


}
