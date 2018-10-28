#include <stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct node
{
    int val,ht;
    struct node *left,*right;
}node;
node *makeNode(int val)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->left=temp->right=NULL;
    temp->val=val;
    temp->ht=1;
}//emake

int height(node *rt)
{
    if(rt==NULL)
        return 0;
    return rt->ht;
}//eheight

int max(int a,int b)
{
    return (a>b)? a:b;
}//emax

void display(node *rt,int space)
{
    if(rt==NULL)
        return ;
    space+=MAX;
    display(rt->right,space);

    for(int i=MAX;i<=space;i++)
        printf(" ");
    printf("%d \n",rt->val);

    display(rt->left,space);
}//edisplay

node *leftRotate(node *rt)
{
    if(rt==NULL)
        return rt;
    node *temp=rt->right;
    rt->right=temp->left;
    temp->left=rt;

    temp->ht=1+max(height(temp->left),height(temp->right));
    rt->ht=1+max(height(rt->left),height(rt->right));

    return temp;
}

node *rightRotate(node *rt)
{
    if(rt==NULL)
        return rt;
    node *temp=rt->left;
    rt->left=temp->right;
    temp->right=rt;

    temp->ht=1+max(height(temp->left),height(temp->right));
    rt->ht=1+max(height(rt->left),height(rt->right));

    return temp;
}

node *ins(node *rt,int val)
{
    node *new_node=makeNode(val);
    if(rt==NULL)
    {
        return new_node;
    }
    else
    {
        if(val<rt->val)
            rt->left=ins(rt->left,val);
        else if(val>rt->val)
            rt->right=ins(rt->right,val);

        else
        {
            //do nothing for duplicate values
        }

        rt->ht=1+max(height(rt->left),height(rt->right));
        int bal=height(rt->left)-height(rt->right);
        printf("\nVal = %d , bal = %d",rt->val,bal);


        if(bal==2 && val<rt->left->val)        //ll case
        {

            rt=rightRotate(rt);
        }
        else if(bal==2 && val>rt->left->val)   //rl case
        {

            rt->left=leftRotate(rt->left);
            rt=rightRotate(rt);
        }
        else if(bal==-2 && val>rt->right->val)  //rr case
        {

            rt=leftRotate(rt);
        }
        else if(bal==-2 && val<rt->right->val)  //lr case
        {

            rt->right=rightRotate(rt->right);
            rt=leftRotate(rt);
        }

    }
    return rt;
}


int main()
{
    int ch=0,val=0;
    node *rt=NULL;
    while(1==1)
    {
        printf("\nPress:\n");
        printf("1:To insert:");
        printf("\n2:To display:");
        printf("\n3:To print the height of the tree:\nAny other no. to exit:\n");

        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nPress -1 to stop: ");
            while(1==1)
            {
                printf("\nEnter any val. to ins: ");
                scanf("%d",&val);
                if(val==-1)
                    break;
                rt=ins(rt,val);
            }

            break;

        case 2:
            printf("\nDisplaying Tree below: \n");
            printf("\n\n\n\n\n\n\n\n\n\n");
            display(rt,0);
            printf("\n\n\n\n\n\n\n\n\n\n");
            break;

        case 3:
            if(rt==NULL)
            {
                printf("\nTree not yet created\n");
                break;
            }
            printf("\nHeight of the tree = %d",rt->ht);
        break;



        default:exit(0);

        }//eswitch

    }//ewhile
}
