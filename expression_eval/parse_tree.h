//
// Created by fxnoob.
//

#ifndef EXPRESSION_EVAL_PARSE_TREE_H
#define EXPRESSION_EVAL_PARSE_TREE_H

#include <stdlib.h>
#include <memory.h>
#include "utils.h"




//basic tree data structure
typedef struct treeInternal{

    struct treeInternal *left;
    struct treeInternal *right;
    char data;

}Tree_;

//typedef tree operation and parsing
typedef void (*parseTree)( Tree_ * , char * );


//tree operations holder DS
typedef struct treeOperationInternal{

    parseTree parse;

}Tree_Op;

typedef struct treeInt{
    Tree_Op operations;
    Tree_ *T;
}Tree;

//stack utils

typedef struct StackInternalParseTree{

    Tree_ **Stack;
    int size;
    void (*push)(struct StackInternalParseTree * , Tree_ *);
    Tree_ *(*pop)(struct StackInternalParseTree * );

}Stack_parse;

void Stack_parse_push(Stack_parse *st , Tree_ *t){
    st->Stack[st->size] = t;
    st->size++;
}
Tree_ *Stack_parse_pop(Stack_parse *st){
    int index = st->size;
    (st->size)--;
    Tree_ *t= st->Stack[--index];
    return t;
}
Stack_parse *construct_parsetree_stack(int size){
    Stack_parse *stack = malloc(sizeof(Stack_parse));
    stack->Stack =  malloc(size*sizeof(Tree_ *));
    stack->size = 0;
    stack->push = Stack_parse_push;
    stack->pop = Stack_parse_pop;
    return stack;
}

void destruct_parsetree_stack(Stack_parse *st){
       free(st->Stack);
       free(st);
}
//initializing tree and its operations
Tree *tree_construct(char *str){

    Tree *t;
    t = (Tree *)malloc(sizeof(Tree));
    t->T = (Tree_ *)malloc(sizeof(Tree_));
    t->T->right = NULL;
    t->T->left = NULL;
    parseTreePlease(t->T,str);
    return t;
}

//free initialized tree
void tree_destruct(Tree *t){
    free(t->T);
    free(t);
}

Tree_ *createNode(){
    Tree_ *t;
    t = (Tree_ *)malloc(sizeof(Tree_));
    t->left = NULL;
    t->right = NULL;
}

void parseTreePlease(Tree_ *t , char *str){
    int i=0;
    char c;
    Tree_ *currentNode;
    Tree_ *parent;
    currentNode = t;
    int str_lenght = strlen(str);
    Stack_parse *stack  = construct_parsetree_stack(str_lenght);
    while(str[i]!='\0'){
        c = str[i];
        // there are four cases -> 1. ( ,  2. integers(operands) , 3. oprerator , 4.)
       if (c != ' '){
           if(c == LEFT_BRACKET){
               Tree_ *temp = createNode();
               currentNode->left = temp;
               //parent = currentNode;
               stack->push(stack , currentNode);
               currentNode = temp;
               i++;
           }
           else if(c == RIGHT_BRACKET){
               currentNode = stack->pop(stack);
               i++;
           }
           else if(isdigit(c)){
               //int num = chars_to_num(i,&i,str,str_lenght);
               currentNode->data = c;
               currentNode = stack->pop(stack);
                i++;
           }
           else if(is_operator(c)){
                currentNode->data = c;
                Tree_ *temp = createNode();
                currentNode->right = temp;
                stack->push(stack , currentNode);
                currentNode = temp;
                i++;
           }
       }

    }
    destruct_parsetree_stack(stack);
}

int toInt(char c){
    int num = c-'0';
    return num;
}

int eval_expr(Tree_ * root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->data);

    // Evaluate left subtree
    int l_val = eval_expr(root->left);

    // Evaluate right subtree
    int r_val = eval_expr(root->right);

    // Check which operator to apply
    if (root->data== PLUS_OPERATOR )
        return l_val+r_val;

    if (root->data==MINUS_OPERATOR)
        return l_val-r_val;

    if (root->data==MULTI_OPERATOR)
        return l_val*r_val;

    if (root->data==DIV_OPERATOR)
        return l_val/r_val;

    return l_val/r_val;
}

#endif //EXPRESSION_EVAL_PARSE_TREE_H
