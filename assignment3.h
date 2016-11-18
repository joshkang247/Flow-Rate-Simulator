#include <stdio.h>
#include <stdlib.h>
#define MaxQueueSize 100
#define NODES 9
#define INF 1000000

struct Edge{
    int flow;
    int flowCap;
};

struct Data{
    int vertex;
};

struct flowNetwork{
    struct Edge ** adjMatrix;
    int visitedNodes[NODES];
    int parent[NODES];
};

struct queueNode{
    struct Data * data;
    struct queueNode * link;
};

struct Queue{
    int currSize;
    struct queueNode * front;
    struct queueNode * rear;
};

void initQueue(struct Queue ** qPtr);
int isQueueFull(struct Queue * Q);
int isQueueEmpty(struct Queue * Q);
void enqueue(struct Queue * Q, struct Data d);
void dequeue(struct Queue * Q, struct Data * d);

struct Edge ** initAdjMatrix();
void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap);
void deleteAdjMatrix(struct Edge ** aM);
void printAdjMat(struct Edge ** aM);

struct flowNetwork * initFlowNetwork();
void deleteFlowNetwork(struct flowNetwork * fN);

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t);
void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t);


