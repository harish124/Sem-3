#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}node;

int size=0;
node *ht[10];

void init()
{
    for(int i=0;i<10;i++)
        ht[i]=NULL;
}//This is used to initialize the hash table

node *makeNode(int val)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->val=val;
    temp->next=NULL;

    return temp;
}
void insert(int val)
{
    int key=val%10;
    node *hd=makeNode(val);
    if(ht[key]==NULL)
    {
        ht[key]=hd;
        ht[key]->next=NULL;
    }
    else
    {
        //We are inserting the new value at the head of the linked list as it takes O(1) time to insert at beginning.
        hd->next=ht[key];
        ht[key]=hd;
    }
}//eins

void display()
{
    for(int i=0;i<10;i++)
    {
        printf("ht[%d] -> ",i);
        if(ht[i]==NULL)
        {
            printf("X");    //X represents NULL
        }
        else
        {
            node *ptr=ht[i];
            while(ptr->next!=NULL)
            {
                printf("%d -> ",ptr->val);
                ptr=ptr->next;
            }
            printf("%d ",ptr->val);
        }
        printf("\n");
    }
}

int search(int val)
{
    int key=val%10;


    if(ht[key]!=NULL)
    {
        if(ht[key]->val==val)    //1st element case
        {

            printf("\nVal found\n");
            return 1;
        }
        else
        {
            //Do a linear search until the val is found
            node *ptr=ht[key];
            while(ptr->next!=NULL && ptr->val!=val)
            {
                ptr=ptr->next;
            }

            if(ptr->val==val)
            {

                printf("\nVal found\n");
                return 1;
            }
            else
            {

                printf("\nVal not found\n");
                return 0;
            }
        }
    }
    else
    {
        printf("\nVal not found\n");
        return 0;
    }
}//esearch

void deleteVal(int val)
{
    int found=search(val);

    if(found)
    {
        int key=val%10;
        node *hd=ht[key];
        if(hd!=NULL)
        {
            if(hd->val==val)        //1st element case
            {
                if(hd->next==NULL)
                {
                    free(hd);
                    ht[key]=NULL;
                    printf("\nVal deleted successfully\n");
                    return;
                }
                else
                {
                    node *ptr=hd;
                    hd=ptr->next;
                    printf("\nVal deleted successfully\n");
                    ht[key]=hd;
                    free(ptr);
                    return;
                }
            }//outer if

            else
            {
                node *ptr=hd,*preptr=hd;

                while(ptr->next!=NULL && ptr->val!=val)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                if(ptr->val==val)
                {
                    preptr->next=ptr->next;
                    free(ptr);
                    printf("\nVal deleted successfully\n");
                    return;
                }
            }
        }
    }

}
int main()
{
    init(); //initialize the hash-table.
    int ch=0,val=0;
    while(1==1)
    {
        printf("\nPress:\n1:To insert\n2:To search\n3:To display\n4:To delete\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nPress -1 to stop:\n");
            while(1==1)
            {
                printf("\nEnter any val: ");
                scanf("%d",&val);
                if(val==-1)
                    break;
                insert(val);
            }
            break;

        case 2:
            printf("\nEnter any val to search: ");
            scanf("%d",&val);
            search(val);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nEnter any val: ");
            scanf("%d",&val);
            deleteVal(val);
        break;

        default:exit(0);
        }
    }

}
