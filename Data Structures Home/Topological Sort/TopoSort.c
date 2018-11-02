#include <stdio.h>
#include <stdlib.h>
#include "queueOperations.h"

int vertices=0;

int topoSort(int mat[][vertices],int vertices)
{
        int indeg[vertices];

        for(int i=0;i<vertices;i++)
        {
            indeg[i]=0;     //initializing values to zero first;
            for(int j=0;j<vertices;j++)
            {
                if(mat[j][i]==1)        //This means no. of edges from j(vertex) to i(vertex); i.e indegree of i;
                {
                    indeg[i]+=1;
                }
            }
            if(indeg[i]==0)
            {
                enqueue(i);             //enqueue all the vertices with in-degree 0 into the queue
            }
        }

        //At this stage all the elements with in-degree 0 has been enqueued.

        while(front!=-1 && front<=rear)     //until queue becomes empty
        {
            int elm=dequeue();
            printf("%c ",elm+65);       //to print as character.
            for(int i=0;i<vertices;i++)
            {
                if(elm==i)
                {
                    continue;       //as start and end vertex should not be the same.
                }
                if(mat[elm][i]==1)      //checking which are all the neighbors of elm
                {
                    indeg[i]-=1;
                    mat[elm][i]=0;      //i.e Remove the edge from elm to i, as we have decreased the in-deg of i by 1 so we have to remove this edge.
                    if(indeg[i]==0)
                    {
                        enqueue(i);             //enqueue all the vertices with in-degree 0 into the queue
                    }
                }

            }
        }
}

int main()
{
    printf("\nEnter the no. of nodes/vertices in the graph: ");

    scanf("%d",&vertices);
    int mat[vertices][vertices];

    printf("\nEnter the adjacency matrix:\n");
    printf("Press:\n1:If there is an edge:\n2:If there is no edge:\nAny other no. will be considered as no edge\n");
    char c='A';

    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            if(i==j)
            {
                continue;   //since graph is acyclic;
            }
            printf("\n%c -> %c\n",c+i,c+j);
            scanf("%d",&mat[i][j]);
        }
    }
    topoSort(mat,vertices);
}//emg
