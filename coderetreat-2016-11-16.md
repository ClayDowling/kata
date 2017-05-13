# Code Retreat 11/18/2016

Implement the Shunting Yard algorithm in java, to convert a mathematical expression
written in infix notation to postfix notation.  The source data will be a string, and
the final output should be a string.  The most straight forward way to do this is
by using the Shunting Yard algorithm.

## Simplified Shunting Yard Algorithm

Given a source string:

* While we can read an input token
  * if the token is a variable [a-z], put it in the output queue.
  * if the token is an operator [^,/,*,-,+] o1:
    * while there is an operator o2 at the top of the operator stack and either
        * o1 is left-associative and its precedence is less than or equal to o2, or
        * o1 is right-associative, and has precedence less than that of o2
      pop o2 off the operator stack and place it into the output queue
    * push o1 onto the operator stack
  * if the token is a left parenthesis '(' the push it onto the operator stack.
  * if the token is a right parenthesis ')':
    - Until the token at the top of the stack is a left parenthesis, pop operators
	    off the stack and into the output queue.
	  - Pop the left parenthesis from the stack, but do not put it into the output
	    queue.
    - If the bottom of the stack is reached without finding a left parenthesis
	    there are mismatched parenthesis, which is an error.
* While there are still operators on the stack:
  * If the operator on the top of the stack is a parenthesis, then there are
    mismatched parenthesis, which is an error.
  * Pop the operator from the stack and into the output queue.


## Operator Precedence

| Operators | Associativity |
| :-------: | ------------- |
| ^         | Right         |
| * /       | Left          |
| + -       | Left          |
