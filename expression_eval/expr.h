//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_EXPR_H
#define EXPRESSION_EVAL_EXPR_H

#include "stack.h"
#include "utils.h"

void expr_check_precedence();

void expr_get_char(char *array , int *index , Stack *post_fix , Stack *operators){
    StackOperations Stack_op;
    Stack_op.push = StackOperation_3_push;
    Stack_op.pop = StackOperation_1_pop;
    char c = array[*index];
    if(c == '')
    {
        *index = *index+1;
    }
    else if(isdigit(c))
    {
        int num = chars_to_num(*index,index,array);
        Stack_op.push(post_fix,&num,'d');

    }
    else if(is_operator(c))
    {
       int opr1_index = get_index(c);
       int opr2_index = get_index(*(char *)operators->root->value);
       if(opr1_index == opr2_index )
       {

       }
       else if(opr1_index > opr2_index )
       {

       }
       else
       {
           //when new operator symbols precedence is less -> pop out the operator and recursively check this

       }
    }
}

#endif //EXPRESSION_EVAL_EXPR_H
