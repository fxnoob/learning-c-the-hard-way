#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "expr.h"

int main(int argc, char const *argv[]) {
    char *str;
    str = (char *)argv[1];
    size_t str_len = strlen(str);
    printf("\n%s = %d\n",str,expr(str , str_len));
    return 0;
}

