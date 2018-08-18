//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_UTILS_H
#define EXPRESSION_EVAL_UTILS_H



int chars_to_num(int from, int to, char *array){
    int decimal = 0,init_count=(int)'0';
    for (int i = from; i <= to; i++) {
        decimal = decimal*10 + (array[i] - init_count);
    }
    return decimal;
}




#endif //EXPRESSION_EVAL_UTILS_H
