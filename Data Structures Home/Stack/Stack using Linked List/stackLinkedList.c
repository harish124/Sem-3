#include <stdio.h>
#include<stdlib.h>

typedef struct st
{
    int val;
    struct st *next;
}st;

st *hd=NULL;
st *push(st *hd,int val)
{
    st *new_node=(st *)malloc(sizeof(st));
    new_node->val=val;
    new_node->next=NULL;

    if(hd==NULL)
    {
        return new_node;
    }
    else
    {
        st *ptr=hd;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }

    return hd;
}//epush

st *pop(st *hd)
{
    if(hd==NULL)
    {
        printf("\nStack underflow\n");
        return hd;
    }
    else
    {

        st *ptr=hd,*preptr=hd;
        if(hd->next==NULL)
        {

            printf("\nVal popped = %d\n",ptr->val);
            hd=NULL;
            return hd;
        }
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;

        }

        //Now ptr->next == NULL
        preptr->next=NULL;
        printf("\nVal popped = %d\n",ptr->val);
        free(ptr);

        return hd;

    }
}
void display(st *hd)
{
    if(hd==NULL)
    {
        printf("\nStack underflow\n");
        return hd;
    }
    st *ptr=hd;
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

    while(1==1)
    {
        printf("\nPress:\n1:To push\n2:To pop\n3:To display the stack\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:printf("\nEnter any val to push: ");
            scanf("%d",&val);
            hd=push(hd,val);
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
