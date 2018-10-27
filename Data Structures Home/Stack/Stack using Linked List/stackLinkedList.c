#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int val;
    struct stack *next;
}st;

st *makeNode(int val)
{

    st *new_node=(st *)malloc(sizeof(st));
    new_node->val=val;
    new_node->next=NULL;
    return new_node;
}

st *push(st *hd,int val)
{
    st *temp=makeNode(val);
    if(hd==NULL)
    {
        return temp;
    }
    else
    {
        temp->next=hd;
        hd=temp;
        return hd;
    }
}
st *pop(st *hd)
{
    if(hd==NULL)
    {
        printf("\nStack is already Empty!!!\n");
        return NULL;
    }
    else
    {
        st *temp=hd;
        printf("\nVal popped = %d",temp->val);
        hd=hd->next;
        free(temp);
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
    st *hd=NULL;
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

        }//eswitch

    }//ewhile

}//emg
