#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node
{
    int val,ht;
    struct node *left,*right;
}node;
node *rt=NULL;

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
node *ins(node *rt,int val)
{
    node *new_node=makeNode(val);
    if(rt==NULL)
    {
        return new_node;
    }
    else
    {
        new_node->ht=1+max(height(rt->left),height(rt->right));

        if(val<rt->val)
            rt->left=ins(rt->left,val);
        else if(val>rt->val)
            rt->right=ins(rt->right,val);

        else
        {
            //do nothing for duplicate values
        }
    }
    return rt;
}//eins

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
node *min(node *rt)
{

    if(rt==NULL)
        return rt;
    else
    {
        node *ptr=rt;
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        return ptr;
    }
}
node *del(node *rt,int val)
{
    if(rt==NULL)
    {
        return rt;
    }
    else
    {

        if(val<rt->val)
            rt->left=del(rt->left,val);
        else if(val>rt->val)
            rt->right=del(rt->right,val);

        else
        {
            //val is found
            node *temp=(node *)malloc(sizeof(node));
            if(rt->left==NULL)
            {
                temp=rt->right;
                free(rt);
                return temp;
            }
            else if(rt->right==NULL)
            {
                temp=rt->left;
                free(rt);
                return temp;
            }
            else if(rt->left!=NULL && rt->right!=NULL)
            {
                temp=min(rt->right);
                rt->val=temp->val;

                rt->right=del(rt->right,temp->val);
            }
        }

    }
    return rt;
}
int totalNodes(node *rt)
{
    if(rt==NULL)
        return 0;
    else
    {
        return totalNodes(rt->left)+totalNodes(rt->right)+1;
    }
}//enodes

int totalInternalNodes(node *rt)
{
    if(rt==NULL)
        return 0;
    if(rt->left==NULL && rt->right ==NULL)
        return 0;
    else
    {
        return totalInternalNodes(rt->left)+totalInternalNodes(rt->right)+1;
    }
}//einternal

int totalExternalNodes(node *rt)
{
    if(rt==NULL)
        return 0;
    if(rt->left==NULL && rt->right ==NULL)
        return 1;
    else
    {
        return totalExternalNodes(rt->left)+totalExternalNodes(rt->right);
    }
}//einternal
node *mirror(node *rt)
{
    if(rt==NULL)
        return rt;
    else
    {
        mirror(rt->left);
        mirror(rt->right);
        node *temp=rt->left;
        rt->left=rt->right;
        rt->right=temp;
        return rt;
    }
}
int main()
{
    int ch=0,val=0;

    while(1==1)
    {
        printf("\nPress:\n");
        printf("\n1:To insert:");
        printf("\n2:To delete:");
        printf("\n3:To display:");
        printf("\n4:To print the height of the tree:");
        printf("\n5:To print the total no. of nodes:");
        printf("\n6:To print the total no. of internal nodes:");
        printf("\n7:To print the total no. of external nodes:");
        printf("\n8:To display the mirror image:\nAny other no. to exit:\n");
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
            printf("\nEnter any val. to delete: ");
            scanf("%d",&val);
            rt=del(rt,val);

        case 3:
            printf("\nDisplaying Tree below: \n");
            printf("\n\n\n\n\n\n\n\n\n\n");
            display(rt,0);
            printf("\n\n\n\n\n\n\n\n\n\n");
            break;

        case 4:
            if(rt==NULL)
            {
                printf("\nTree not yet created\n");
                break;
            }
            printf("\nHeight of the tree = %d",rt->ht);
        break;

        case 5:printf("\nTotal no. of nodes in the tree = %d",totalNodes(rt));
        break;

        case 6:printf("\nTotal no. of internal nodes(at-least 1 child) in the tree = %d",totalInternalNodes(rt));
        break;

        case 7:printf("\nTotal no. of external nodes(no child) in the tree = %d",totalExternalNodes(rt));
        break;

        case 8:
            printf("\nDisplaying Mirror Image below: \n");
            printf("\n\n\n\n\n\n\n\n\n\n");
            display(mirror(rt),0);
            printf("\n\n\n\n\n\n\n\n\n\n");
            break;

        default:exit(0);
        }
    }
}//emg
