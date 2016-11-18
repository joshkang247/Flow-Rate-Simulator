#include "assignment3.h"

void initQueue(struct Queue ** qPtr)
{
    struct Queue * Q=(struct Queue *)malloc(sizeof(struct Queue));
    Q->currSize=0;
    Q->front=NULL;
    Q->rear=NULL;
    *qPtr=Q;
}

int isQueueFull(struct Queue * Q)
{
    if (Q->currSize==MaxQueueSize) {
        return 1;
    }
    else{
        return 0;
    }
}

int isQueueEmpty(struct Queue * Q)
{
    if (Q->currSize==0) {
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct Queue * Q, struct Data d)
{
    struct queueNode * newNode;
    if (!isQueueFull(Q)) {
        newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
        newNode->data=(struct Data *)malloc(sizeof(struct Data));
        *(newNode->data)=d;
        newNode->link=NULL;
        if (Q->rear==NULL) {
            Q->rear=newNode;
            Q->front=newNode;
        }
        else
        {
            Q->rear->link=newNode;
            Q->rear=newNode;
        }
        Q->currSize++;
    }
}

void dequeue(struct Queue * Q, struct Data * d)
{
    struct queueNode * temp;
    if (!isQueueEmpty(Q)) {
        temp=Q->front;
        *d=*(temp->data);
        if (Q->front==Q->rear) {
            Q->front=NULL;
            Q->rear=NULL;
        }
        else{
            Q->front=temp->link;
        }
        free(temp->data);
        free(temp);
        Q->currSize--;
    }
}
