#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node;

typedef struct q
{
    node *front,*rear;
}q;

q *hd=NULL;

q *createQ(q *hd)
{
    hd->front=hd->rear=NULL;
    return hd;
}
node *makeNode(int val)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->val=val;
    temp->next=NULL;

    return temp;
}
q *enqueue(q *hd,int val)
{
    node *new_node=makeNode(val);
    if(hd->front==NULL &&hd->rear==NULL)
    {
        hd->front=hd->rear=new_node;
        hd->front->next=hd->rear->next=NULL;
        return hd;
    }
    else
    {
        hd->rear->next=new_node;
        hd->rear=new_node;
        hd->rear->next=NULL;
    }
    return hd;
}
q *pop(q *hd)
{
    if(hd->front==NULL)
    {
        printf("\nQueue already empty!!\n");
        hd->front=hd->rear=NULL;
        return  hd;
    }
    else
    {
        node *ptr=hd->front;
        printf("\nVal popped = %d",ptr->val);
        hd->front=hd->front->next;
        free(ptr);
    }

    return hd;
}
void display(q *hd)
{
    if(hd->front==NULL)
    {
        printf("\nQueue already empty!!\n");
        hd->front=hd->rear=NULL;
        return  hd;
    }
    node *ptr=hd->front;

    while(ptr!=NULL)
    {
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    int ch=0,val=0,temp=0;
    hd=(q *)malloc(sizeof(q));
    hd=createQ(hd);
    while(1==1)
    {
        printf("\nPress:\n1:To enqueue\n2:To dequeue\n3:To display the queue\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:printf("\nEnter any val to push: ");
            scanf("%d",&val);
            hd=enqueue(hd,val);
            break;

            case 2:hd=pop(hd);
            break;

            case 3:
                display(hd);
                break;

            default:exit(0);
        }
    }
}
