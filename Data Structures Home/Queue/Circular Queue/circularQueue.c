#include <stdio.h>
#include <stdlib.h>

int size=0;
int rear=-1,front=-1;
void enqueue(int q[],int val)
{
    if((front==0 && rear==size -1)|| front==rear+1)
    {
        printf("\nOverflow!!\nVal not inserted\n");
        return;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%size;
        q[rear]=val;
    }

}
void dequeue(int q[])
{
    if(front==-1)
    {
        printf("\nUnderflow!!\n");
    }
    else
    {
        int elm=q[front];
        if(front==rear)
        {

            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        printf("\nVal popped = %d",elm);


    }
}
void display(int q[])
{
    if(front==-1)
    {
        printf("\nQueue is already empty\n");
        return;
    }
    int i=front;
    for(i=front;i!=rear;i=(i+1)%size)
    {
        printf("%d ",q[i]);
    }
    printf("%d \n",q[i]);
}
int main()
{
    printf("\nEnter the size of the Queue: ");
    scanf("%d",&size);
    int q[size];
    int ch=0;
    int temp=0;
    while(1==1)
    {
        printf("\nPress:\n1:To enqueue\n2:To dequeue\n3:To display\nAny other no. to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter any val: ");
            int val=0;
            scanf("%d",&val);
            enqueue(q,val);
            break;

        case 2:
            dequeue(q);

            break;

        case 3:
            display(q);
            break;

        default:exit(0);
        }
    }
}
