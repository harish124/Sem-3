#include <stdio.h>
#include<stdlib.h>
int q[100],rear=-1,front=-1,qSize=0;

void enqueue(int val)

{

    if(front>rear)

    {

        front=rear=-1;   //reseting the Queue after all the elements are dequeueped

    }

    if(rear==qSize-1)

    {

        printf("\nQueue overflow!!!!\nVal not inserted\n");

        return ;

    }

    else

    {

        if(front==-1 && rear==-1)

        {

            front=rear=0;

            q[rear]=val;

        }

        else

        {

            q[++rear]=val;

        }

    }

}//epush



int dequeue()

{

    if(front==-1 || front >rear)

    {

        printf("\nQueue underflow\n");

        return -1;

    }

    else

    {

        return q[front++];

    }

}

void display()

{

    if(front==-1 || front >rear)

    {

        printf("\nQueue underflow\n");

        return ;

    }

    for(int i=front;i<=rear;i++)

    {

        printf("%d ",q[i]);

    }

    printf("\n");

}


