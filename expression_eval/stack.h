//
// Created by fxnoob
//

#ifndef EXPRESSION_EVAL_STACK_H
#define EXPRESSION_EVAL_STACK_H
#include <stdlib.h>
/*

DS : Stack
operations : push , pop , search , size

*/

typedef struct LinkedListInternal
{
    char value;
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
typedef void (*StackOperation_1)(Stack *);
typedef void (*StackOperation_2)(Stack *,char);


typedef struct StackOperationsInternal
{
    StackOperation_2 push;
    StackOperation_1 pop ;
    StackOperation_1_wptr traverse;

}StackOperations;

/*
LinkedList operations
starts:
*/

void LinkedListOperation_2_add(LinkedList **root,char value)
{
    if (*root == NULL)
    {
        *root = (LinkedList *)malloc(sizeof(LinkedList));
        (*root)->value = value;
        (*root)->next = NULL;
    }
    else
    {
        LinkedList *node;
        node = (LinkedList *)malloc(sizeof(LinkedList));
        node->value = value;
        node->next = *root;
        *root = node;
    }

}

void LinkedListOperation_1_delete_last_added(LinkedList **root)
{
    if (*root == NULL)
    {
        free(*root);
    }
    else
    {
        LinkedList *tmp;
        tmp = *root;
        *root = (*root)->next;
        free(tmp);
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
void StackOperation_2_push(Stack *S,char value)
{
    LinkedListOperation_2_add(&(S->root),value);
    (S->size)++;
}

void StackOperation_1_pop(Stack *S)
{
    LinkedListOperation_1_delete_last_added(&(S->root));
    (S->size)--;

}

void StackOperation_1_traverse(Stack S)
{
    LinkedList *current;
    int count = S.size;
    current = S.root;
    while (count)
    {
        printf("value=%c\n",current->value);
        current = current->next;
        count--;
    }

}

#endif //EXPRESSION_EVAL_STACK_H
