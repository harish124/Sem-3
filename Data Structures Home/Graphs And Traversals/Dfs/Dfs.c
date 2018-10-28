#include<stdio.h>
#include<stdlib.h>
#include "Matrix.h"
#include "stackOperations.c"
int size=0;
void dfsRecursive(int mat[][100],int start,int visited[100])
{
    visited[start]=1;
    printf("%c ",start+65);
    for(int i=0;i<size;i++)
    {
        if(mat[start][i]==1 && visited[i]!=1)
        {
            dfsRecursive(mat,i,visited);
        }

    }
}

void dfsUsingStack(int mat[][100],int start,int visited[100])
{
    //set stack size to size
    Stsize=size;
    int temp=0;
    push(start);
    temp=start;
    visited[temp]=1;
    printf("%c ",temp+65);
    int i=0,done=0;

    while(top!=-1)  //that is until stack becomes empty
    {

        for(i=0;i<size;i++)
        {
            if(mat[temp][i]==1 && visited[i]!=1)
            {
                visited[i]=1;
                push(i);
                printf("%c ",i+65);
                done=1;
                break;
            }
        }
        if(done==1)
        {
            done=0;
            temp=i;
        }
        else
        {
            pop();
            temp=st[top];
        }
    }
}

int main()
{

    printf("\nEnter the no. of vertices: ");
    scanf("%d",&size);
    int mat[100][100],visited[size];
    makeMatrix(mat,size);
    displayMat(mat,size);
    setStartVertex();

    //Note: Both the below functions are working ,choose any one at a time and comment out the other

    //dfsRecursive(mat,start,visited);

    dfsUsingStack(mat,start,visited);
}
