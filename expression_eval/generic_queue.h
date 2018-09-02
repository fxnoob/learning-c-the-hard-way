//
// Created by root on 9/2/18.
//

#ifndef EXPRESSION_EVAL_GENERIC_QUEUE_H
#define EXPRESSION_EVAL_GENERIC_QUEUE_H

typedef struct {
    void *elems;
    int elemSize;
    int front;
    int logLength;
    int allocLength;
}Generic_Queue;

#define  Generic_Queue_kInitialAllocationSize 4

#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

void ini_Generic_Queue(Generic_Queue *s,int elemSize);
void destruct_Generic_Queue(Generic_Queue *s);
bool empty_Generic_Queue(const Generic_Queue *s);
void Generic_Queue_push(Generic_Queue *s, const void *elemAddr);
void Generic_Queue_pop(Generic_Queue *s, void *elemAddr);


void ini_Generic_Queue(Generic_Queue *s,int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->front = 0;
    s->logLength = 0;
    s->allocLength = Generic_Queue_kInitialAllocationSize;
    s->elems = malloc(Generic_Queue_kInitialAllocationSize * elemSize);
    assert(s->elems != NULL);
}

void destruct_Generic_Queue(Generic_Queue *s)
{
    free(s->elems);
}

bool empty_Generic_Queue(const Generic_Queue *s)
{
    return s->logLength == 0;
}

void Generic_Queue_push(Generic_Queue *s, const void *elemAddr)
{
    void *destAddr;
    if (s->logLength == s->allocLength) {
        s->allocLength *= 2;
        s->elems = realloc(s->elems, s->allocLength * s->elemSize);
        assert(s->elems != NULL);
    }
    destAddr = (char *)s->elems + s->logLength * s->elemSize;
    memcpy(destAddr, elemAddr, s->elemSize);
    s->logLength++;
}

void Generic_Queue_pop(Generic_Queue *s, void *elemAddr)
{
    const void *sourceAddr;
    assert(!empty_Generic_Queue(s));
    s->logLength--;
    sourceAddr = (const char *) s->elems + s->front * s->elemSize;
    s->front++;
    memcpy(elemAddr, sourceAddr, s->elemSize);
}

#endif //EXPRESSION_EVAL_GENERIC_QUEUE_H
