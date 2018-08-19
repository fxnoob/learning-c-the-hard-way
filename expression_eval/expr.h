//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_EXPR_H
#define EXPRESSION_EVAL_EXPR_H

#include <stdio.h>
#include "stack.h"
#include "utils.h"

void pop_by_precedence(char operator_chr , Stack *post_fix , Stack *operators)
{
    if(operators->size>0)
    {
        int opr1_index = get_index(operator_chr);
        char opr_2 = *(char *)operators->root->value;
        int opr2_index = get_index(opr_2);
        if((opr1_index <= opr2_index) && (opr2_index != 10 ) )
        {
            StackOperations Stack_op;
            Stack_op.push = StackOperation_3_push;
            Stack_op.pop = StackOperation_1_pop;
            LinkedList *L1;
            L1 = Stack_op.pop(operators);
            Stack_op.push(post_fix,L1->value,L1->dataType);
            pop_by_precedence(operator_chr,post_fix,operators);

        }
    }

}

void pop_until_left_prenthesis(Stack *post_fix , Stack *operators)
{
    if(operators->size>0)
    {
        StackOperations Stack_op;
        Stack_op.push = StackOperation_3_push;
        Stack_op.pop = StackOperation_1_pop;
        LinkedList *L1;
        char opr_t = *(char *)operators->root->value;
        if(opr_t == LEFT_BRACKET)
        {
            Stack_op.pop(operators);
        }
        else
        {
           L1 = Stack_op.pop(operators);
           Stack_op.push(post_fix,L1->value,L1->dataType);
           pop_until_left_prenthesis(post_fix,operators);
        }
    }
    else
    {
        printf("Invalid infix notation");
    }


}

void infix_to_postfix(char *array , int *index , Stack *post_fix , Stack *operators,int str_lenght){
  if(*index < str_lenght)
  {
      StackOperations Stack_op;
      Stack_op.push = StackOperation_3_push;
      Stack_op.pop = StackOperation_1_pop;
      LinkedList *L1;
      char c = array[*index];
      if(c == '')
      {
          *index = *index+1;
          infix_to_postfix(array,index,post_fix,operators,str_lenght);
      }
      else if(isdigit(c))
      {
          int num = chars_to_num(*index,index,array);
          Stack_op.push(post_fix,&num,'d');
          infix_to_postfix(array,index,post_fix,operators,str_lenght);
      }
      else if(is_operator(c))
      {
          int opr1_index = get_index(c);
          int opr2_index = get_index(*(char *)operators->root->value);
          if( opr1_index ==10 )
          {
            if (c == LEFT_BRACKET)
            {
                Stack_op.push(operators,&c,'c');
                *index = *index+1;
                infix_to_postfix(array,index,post_fix,operators,str_lenght);
            }
            else if (c == RIGHT_BRACKET)
            {
                //pop operators stack until LEFT perendthisis comes
                pop_until_left_prenthesis(post_fix,operators);
                *index = *index+1;
                infix_to_postfix(array,index,post_fix,operators,str_lenght);
            }
          }
          else if(opr1_index <= opr2_index )
          {
              //when both operators are of the same precedence eg + and - or * and /
              pop_by_precedence(c,post_fix,operators);
              *index = *index+1;
              infix_to_postfix(array,index,post_fix,operators,str_lenght);
          }
          else if(opr1_index > opr2_index )
          {
              Stack_op.push(operators,&c,'c');
              *index = *index+1;
              infix_to_postfix(array,index,post_fix,operators,str_lenght);
          }
          else
          {
              printf("\nError in evaluating expression\n");
          }
      }
  }
}

#endif //EXPRESSION_EVAL_EXPR_H
