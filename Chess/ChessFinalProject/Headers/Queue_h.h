#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>


typedef struct Queue{
    char data[3];
    int move;
    struct Queue * next;
}Queue;

extern Queue * front , * rear;

void init();
void enQueue(char * data,int move);
void deQueue(char * move , int * n);
void printQueueForK();
void printQueueForR();
#endif