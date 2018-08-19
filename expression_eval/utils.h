//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_UTILS_H
#define EXPRESSION_EVAL_UTILS_H

#include <ctype.h>

#define PLUS_OPERATOR '+'
#define MINUS_OPERATOR '-'
#define MULTI_OPERATOR '*'
#define DIV_OPERATOR '/'
#define POW_OPERATOR '^'
#define LEFT_BRACKET '('
#define RIGHT_BRACKET ')'


int chars_to_num(int from, int *toIndex, char *array){
    int decimal = 0,i,init_count=(int)'0';
    for (i = from; isdigit(array[i])&&array[i]!='\0'; i++) {
        decimal = decimal*10 + (array[i] - init_count);
    }
    *toIndex = i;
    return decimal;
}




#endif //EXPRESSION_EVAL_UTILS_H
