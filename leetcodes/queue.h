//
// Created by root on 8/25/18.
//

#ifndef LEETCODES_QUEUE_H
#define LEETCODES_QUEUE_H

//
// Created by fxnoob.
//

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define SIZE 1000


typedef struct {
    int size;
    int head , tail ;
    int data[SIZE];
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue *);
bool myCircularQueueIsFull(MyCircularQueue* );

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *mcq;
    mcq = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    mcq->size = k ;
    mcq->head = -1 ;
    mcq->tail = -1 ;
    return mcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    } else{
        if(myCircularQueueIsEmpty(obj))
            obj->head = 0;
        obj->tail = (obj->tail + 1)%(obj->size);
        obj->data[obj->tail] = value;
        return true;
    }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }else{
        if (obj->head == obj->tail) {
            obj->head = -1;
            obj->tail = -1;
            return true;
        }
        obj->head = (obj->head + 1)%(obj->size);
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    int data[1000];
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }else{
        return obj->data[obj->head];
    }
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    int data[1000];
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }else{
        return obj->data[obj->tail];
    }
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    bool ret = (obj->tail == -1)?true:false;
    return ret;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int currentSize = (obj->tail+1)%(obj->size);
    int head = obj->head;
    if(head == currentSize)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}


#endif //LEETCODES_QUEUE_H
