#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "expr.h"

int main(int argc, char const *argv[]) {
    char *str = "2+3";
    int str_len = strlen(str);
    printf("%s = %d",str,expr(str , str_len));
    return 0;
}

