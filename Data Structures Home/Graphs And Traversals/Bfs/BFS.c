#include<stdio.h>
#include<stdlib.h>
#include "QueueOperations.h"
int size=0;

void bfs(int mat[4][4],int start)
{
    int visited[10]={0};
    visited[start]=1;
    int temp=start;
    enqueue(start);
    int done=1;

    while(front!=-1 && front<=rear)
    {
        for(int i=0;i<size;i++)
        {
            if(mat[temp][i]==1 && visited[i]!=1)
            {
                enqueue(i);
                visited[i]=1;

            }
        }

        printf("%c ",dequeue()+65);
        temp=q[front];
    }
}
int main()
{

    printf("\nEnter the no. of vertices: ");
    scanf("%d",&size);
    int count = 0;
    //Make the adjacency matrix
    char c='A';
    int mat[size][size];
    //int mat1[4][4]={{0,1,1,0},{0,0,1,0},{1,0,0,1},{0,0,0,1}};  //Test case : Answer for this is CADB
    printf("Press:\n1:If there is an edge:\n2:If there is no edge:\nAny other no. will be considered as no edge\n");
    for(i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {

            printf("%c -> %c\n",c+i,c+j);
            scanf("%d",&mat[i][j]);
        }
    }

    //set qSize in header file to size
    qSize=size;
    printf("\nPress any number to start from that particular character: \n");
    for(char ch='A',count=0;ch<=65+size-1;ch++,count++)
    {
        printf("%d --> %c\n",count,ch);
    }
    int start=0;
    scanf("%d",&start);

    if(start>=0 && start<=size-1)
    {
        bfs(mat1,start);
    }
    else
    {
        printf("\nInvalid Start Index\n");
        exit(0);
    }
}
