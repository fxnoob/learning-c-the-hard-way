#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "utils.h"
#include "expr.h"
#include "generic_queue.h"

int main(int argc, char *argv[])
{
    int val;
    Generic_Queue temp;
    Generic_Queue intQueue;
    ini_Generic_Queue(&intQueue, sizeof(int));
    for (val = 0; val < 6; val++){
        Generic_Queue_push(&intQueue, &val);
         //StackPush(&intStack, &val);
    }
    while (!empty_Generic_Queue(&intQueue)) {
        //StackPop(&intStack, &val);
        Generic_Queue_pop(&intQueue,&val);
        printf("This just popped: %d\n", val);
    }
    destruct_Generic_Queue(&intQueue);
   return 0;
}

