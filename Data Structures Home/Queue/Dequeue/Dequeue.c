#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,size=0;
int isFull()
{
    if(front==(rear+1)%size)
    {
        return 1;
    }

    return 0;
}

int isEmpty()
{
    if(rear==-1)
    {
        return 1;
    }
    return 0;
}
void display(int q[])
{
    int i=front;
    if(isEmpty())
    {
        printf("\nIs empty!!\n");
        return;
    }
    for(i=front;i!=rear;i=(i+1)%size)
    {
        printf("%d ",q[i]);
    }
    printf("%d \n",q[i]);
}

void enqR(int q[],int val)
{
    if(isEmpty())
    {
        front=rear=0;
        q[rear]=val;
        return;
    }
    else
    {
        rear=(rear+1)%size;
        q[rear]=val;
        return;
    }
}
void enqF(int q[],int val)
{
    //Spl case of dequeue
    if(isEmpty())
    {
        front=rear=0;
        q[front]=val;
        return;
    }
    else
    {
        front=(front-1+size)%size;  //This line is different from dqF
        q[front]=val;
        return;
    }
}
int dqF(int q[])
{
    int elm=q[front];
    printf("\nVal popped = %d\n",elm);
    if(front==rear)
    {
        //single element case
        front=rear=-1;
        return 1;
    }
    else
    {
        front=(front+1)%size;
    }
}

int dqR(int q[])
{
    //Spl case of dequeue
    int elm=q[rear];
    printf("\nVal popped = %d\n",elm);
    if(front==rear)
    {
        //single element case
        front=rear=-1;
        return 1;
    }
    else
    {
        rear=(rear-1+size)%size;    //This line is different from dqF
    }
}
int main()
{
    printf("\nEnter the size: ");
    scanf("%d",&size);
    int q[size];
    int ch=0,val=0;
    while(1==1)
    {
        printf("\nPress:\n1:To enqR\n2:To dqF\n3:To display\n4:To enqF\n5:To dqR\nAny other no. to exit:\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nEnter any val: ");
            scanf("%d",&val);
            if(!isFull())
                enqR(q,val);
            else
            {
                printf("\nOverflow!!\n");
            }
            break;

        case 2:
            if(!isEmpty())
                dqF(q);
            else
            {
                printf("\nUnderflow!!\n");
            }
        break;

        case 3:display(q);
        break;

        case 4:
            printf("\nEnter any val: ");
            scanf("%d",&val);
            if(!isFull())
                enqF(q,val);
            else
            {
                printf("\nOverflow!!\n");
            }
            break;

        case 5:
            if(!isEmpty())
                dqR(q);
            else
            {
                printf("\nUnderflow!!\n");
            }
            break;

        default:exit(0);
        }
    }
}
