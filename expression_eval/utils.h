//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_UTILS_H
#define EXPRESSION_EVAL_UTILS_H

#include <ctype.h>

// priority index in the comments
#define PLUS_OPERATOR '+' //0
#define MINUS_OPERATOR '-' //0
#define MULTI_OPERATOR '*'// 1
#define DIV_OPERATOR '/'// 1
#define POW_OPERATOR '^'// 2
#define LEFT_BRACKET '('//10
#define RIGHT_BRACKET ')'//10


int chars_to_num(int from, int *toIndex, char *array , int str_lenght){
    int decimal = 0,i,init_count=(int)'0';
    for (i = from; isdigit(array[i])&&array[i]!='\0'&&from<str_lenght; i++) {
        decimal = decimal*10 + (array[i] - init_count);
    }
    *toIndex = i;
    return decimal;
}

int is_operator(char operator){
    int res = 0;
    switch(operator){
        case PLUS_OPERATOR:
        case MINUS_OPERATOR:
        case MULTI_OPERATOR:
        case DIV_OPERATOR:
        case POW_OPERATOR:
        case LEFT_BRACKET:
        case RIGHT_BRACKET:
            res = 1;
            break;
        default:
            res = 0;
    }
    return res;
}

//getting priority index of the operator , as C does not has associative array
int get_index(char operator){
    int res = -1;
    switch(operator){
        case PLUS_OPERATOR:
        case MINUS_OPERATOR:
            res = 0;
            break;
        case MULTI_OPERATOR:
        case DIV_OPERATOR:
            res = 1;
            break;
        case POW_OPERATOR:
            res = 2;
            break;
        case LEFT_BRACKET:
        case RIGHT_BRACKET:
            res = 10;
            break;
        default:
            res = -1;
    }
    return res;
}

#endif //EXPRESSION_EVAL_UTILS_H
