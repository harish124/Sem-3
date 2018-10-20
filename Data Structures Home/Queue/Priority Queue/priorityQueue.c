#include<stdio.h>
#include <stdlib.h>

typedef struct pq
{
    int val;
    struct pq *next;
    int pri;
}node;

node *makeNode(int val,int pri)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->val=val;
    temp->pri=pri;
    temp->next=NULL;
    return temp;
}
node *insert(node *hd,int val,int pri)
{
    node *new_node=makeNode(val,pri);
    if(hd==NULL || hd->pri>pri)
    {
        new_node->next=hd;
        hd=new_node;
        return hd;
    }
    else
    {
        node *ptr=hd;
        while(ptr->next!=NULL && ptr->next->pri<=pri)
        {
            ptr=ptr->next;
        }

        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    return hd;
}
void display(node *hd)
{

    if(hd==NULL)
    {
        printf("\nEmpty Queue\n");
        return;
    }
    else
    {
        node *ptr=hd;
        while(ptr!=NULL)
        {
            printf("%d[ pri = %d ]\t",ptr->val,ptr->pri);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    node *hd=NULL;
    int ch=0,val=0,pri=0;
    while(1==1)
    {
        printf("\nPress:\n1:To insert\n2:To delete\n3:To display\nAny other no. to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            printf("\nEnter any val to insert: ");
            scanf("%d",&val);
            printf("\nEnter its priority: ");
            scanf("%d",&pri);
            hd=insert(hd,val,pri);
            break;

        case 3:display(hd);
        break;

        default:exit(0);
        }
    }
}
