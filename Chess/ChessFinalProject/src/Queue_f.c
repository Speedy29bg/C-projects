#include"..\Headers\Queue_h.h"
#include <string.h>
#include<stdlib.h>

void init(){
    front=NULL;
    rear=NULL;
}

void enQueue(char * data , int move){
    Queue * current =(Queue*)malloc(sizeof(Queue));
    strcpy(current->data,data);
    current->move=move;
    current->next=NULL;
    if(front==NULL){
        front=current;
        rear=current;
        return;
    }
    rear->next=current;
    rear=current;
}

 void deQueue(char * move ,int * n){
    Queue * current = front;
    if(front==NULL){
        printf("The queue is empty:");
        exit(0);
    }
    if(front==rear){
        front=NULL;
        rear=NULL;
        strcpy(move,current->data);
        *n = current->move;
        free(current);
        return;
    }
    
    strcpy(move,current->data);
    *n = current->move;
    front=front->next;
    free(current);
}

void printQueueForK(){
    Queue * temp = front;
    while(temp!=NULL){
        printf("%s ->",temp->data);
        temp=temp->next;
    }
    printf(" end\n");
    
}

void printQueueForR(){
    Queue * temp = front;
    while(temp!=NULL){
        printf("%s %d ->",temp->data,temp->move);
        temp=temp->next;
    }
    printf(" end\n");

}