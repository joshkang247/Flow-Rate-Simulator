#include "assignment3.h"

struct flowNetwork * initFlowNetwork(){
        struct flowNetwork * init = (struct flowNetwork *)malloc(sizeof(struct flowNetwork));
        init->adjMatrix = initAdjMatrix();
        int i;
        for (i=0;i<NODES;i++)
        {
                init->visitedNodes[i] = 0;
                init->parent[i] = -1;
        }
}

void deleteFlowNetwork(struct flowNetwork * fN){
        deleteAdjMatrix(fN->adjMatrix);
        free(fN);
        fN = NULL;
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
        int i,j;
        for (i=0;i<NODES;i++)
        {
                fN->visitedNodes[i] = 0;	
        }

        struct Queue * q;
        struct Data data;
        data.vertex = s;
        initQueue(&q);
        enqueue(q, data);

        while (isQueueEmpty(q) == 0)
        {
                dequeue(q, &data);
                s = data.vertex;
                for (i=0;i<NODES;i++)
                {
                        if (((fN->adjMatrix[s][i].flowCap - fN->adjMatrix[s][i].flow) > 0) && (fN->visitedNodes[i] == 0))
                        {
                                fN->parent[i] = s;
                                data.vertex = i;
                                enqueue(q, data);
                                fN->visitedNodes[i] = 1;
                        }
                }
        }
        free(q);
        q = NULL;
        if (fN->visitedNodes[t] == 0)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
	int a,i,j,max,parent, end = t;

	while (breadthFirstPathSearch(fN, s, t) == 1)
	{
		max = 0;		
		a = 1;
		
		while(a==1)
		{
			max++;
			while (end > 0)
			{
				parent = fN->parent[end];
				if (fN->adjMatrix[parent][end].flow + max == fN->adjMatrix[parent][end].flowCap)
				{
					a = 0;		
				}
				end = parent;
			}
			end = t;
		}
	
		while (end > 0)
		{
			parent = fN->parent[end];
			fN->adjMatrix[parent][end].flow += max;
			end = parent;
		}	
		end = t;	
	}
}
