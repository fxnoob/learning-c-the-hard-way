#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "expr.h"
#include "parse_tree.h"

int main(int argc, char const *argv[]) {

    char str[] = "((4+3)*5)";
    Tree *T = tree_construct(str);
    printf("ans=%d",eval_expr(T->T));
    return 0;
}

