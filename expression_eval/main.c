#include <stdio.h>
#include "stack.h"

int main() {
    Stack s1 ;

    StackOperations Stack_op;
    Stack_op.push = StackOperation_2_push;
    Stack_op.pop = StackOperation_1_pop;
    Stack_op.traverse = StackOperation_1_traverse;

    Stack_op.push(&s1,'a');
    Stack_op.push(&s1,'b');
    Stack_op.pop(&s1);
    Stack_op.push(&s1,'c');
    Stack_op.traverse(s1);
    return 0;
}

