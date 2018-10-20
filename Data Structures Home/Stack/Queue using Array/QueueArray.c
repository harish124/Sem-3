#include <stdio.h>
#include<stdlib.h>

int q[100],rear=-1,front=-1,size=0;
void enqueue(int val)
{
    if(front>rear)
    {
        front=rear=-1;   //reseting the Queue after all the elements are dequeueped
    }
    if(rear==size-1)
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
int main()
{
    printf("\nEnter the size of the Queue:\n");
    scanf("%d",&size);
    int ch=0,val=0,temp=0;

    while(1==1)
    {
        printf("\nPress:\n1:To enqueue\n2:To dequeue\n3:To display the Queue\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:printf("\nEnter any val to enqueue: ");
            scanf("%d",&val);
            enqueue(val);
            break;

            case 2:temp=dequeue();
            if(temp!=-1)
            {
                printf("\nVal popped = %d\n",temp);
            }
            break;

            case 3:
                display();
                break;

            default:exit(0);
        }
    }
}
