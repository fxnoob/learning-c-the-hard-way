//
// Created by fxnoob
//

#ifndef EXPRESSION_EVAL_STACK_H
#define EXPRESSION_EVAL_STACK_H
#include <ctype.h>
#include <memory.h>

/*

DS : Stack
operations : push , pop , search , size

*/

typedef struct LinkedListInternal
{
    void *value;
    char dataType;
    struct LinkedListInternal *next;

}LinkedList;


//linked list operation : add ,delete ,search
typedef void (*LinkedListOperation_1)(LinkedList **);
typedef void (*LinkedListOperation_2)(LinkedList **,char);

typedef struct LinkedListOperationsInternal
{
    int size;
    LinkedListOperation_1 delete , delete_last , serach ;
    LinkedListOperation_2 add;

}LinkedListOperations;


typedef struct stackInternal
{
    LinkedList *root;
    int size;

}Stack;

//stackoperations : push , pop
typedef void (*StackOperation_1_wptr)(Stack );
typedef LinkedList *(*StackOperation_1)(Stack *);
typedef void (*StackOperation_3)(Stack *,void *,char);


typedef struct StackOperationsInternal
{
    StackOperation_3 push;
    StackOperation_1 pop ;
    StackOperation_1_wptr traverse;

}StackOperations;

/*
LinkedList operations
starts:
*/

void LinkedListOperation_3_add(LinkedList **root,void *value,char dataType)
{
       LinkedList *node;
        node = (LinkedList *)malloc(sizeof(LinkedList));
        if (dataType == 'c')
        {
            node->value = (char *) malloc(sizeof(char));
            node->dataType = 'c';
            /* using memcpy to copy string: */
            memcpy(node->value, value,1);
        }
        else if(dataType == 'd')
        {
            node->value = (int *)malloc(sizeof(int));
            node->dataType = 'd';
            /* using memcpy to copy string: */
            memcpy(node->value, value,1);
        }
        node->next = *root;
        *root = node;

}

LinkedList *LinkedListOperation_1_delete_last_added(LinkedList **root)
{
    void *ptr;
    if (*root == NULL)
    {
        //free(*root);
        return *root;
    }
    else
    {
        LinkedList *tmp;
        tmp = *root;
        *root = (*root)->next;
        //free(tmp);
        return tmp;
    }

}

/*
LinkedList operations
End:
*/

/*
* Stack operations
*
*/

void StackOperation_3_push(Stack *S,void *value, char dataType)
{
    LinkedListOperation_3_add(&(S->root),value,dataType);
    (S->size)++;
}

LinkedList *StackOperation_1_pop(Stack *S)
{
    (S->size)--;
    return LinkedListOperation_1_delete_last_added(&(S->root));

}

void StackOperation_1_traverse(Stack S)
{
    LinkedList *current;
    char *val;
    int count = S.size;
    current = S.root;

    while (count)
    {
        val = current->value;
        if (current->dataType == 'd') {
            printf("value=%d\n",*val);
        }
        else if(current->dataType =='c') {
            printf("value=%c\n",*val);
        }

        current = current->next;
        count--;
    }

}

#endif //EXPRESSION_EVAL_STACK_H
