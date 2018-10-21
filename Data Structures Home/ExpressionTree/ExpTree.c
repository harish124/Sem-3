#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
typedef struct node
{
    int val;
    char c;
    struct node *left ,*right;
}node;
node *st[100];
int top=-1;
void push(node *temp)
{
    if(top==99)
    {
        printf("\nOverflow!!");
        return;
    }
    else
    {
        st[++top]=temp;
        //printf("\nTop after pushing = %d",top);
    }
}
node *pop()
{
    if(top==-1)
    {
        printf("\nUnderflow!!\n",top);
        return NULL;
    }
    else
    {
        return st[top--];
    }
}
void display(node *hd,int space)
{
    if(hd==NULL)
    {
        return;
    }
    space+=MAX;
    display(hd->right,space);
    for(int i=MAX;i<=space;i++)
        printf(" ");
    if(hd->val==-1)
    {
        printf("%c \n",hd->c);
    }
    else
    {
        printf("%d \n",hd->val);
    }

    display(hd->left,space);
}
void eval(char str[])
{
    int i=0,val=0;
    while(str[i]!='\0')
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->left=temp->right=NULL;
        if(isalpha(str[i]))
        {
            printf("\nEnter any val for %c: ",str[i]);
            scanf("%d",&temp->val);
            temp->c=str[i];
            push(temp);
        }
        else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        {
            temp->right=pop();
            temp->left=pop();
            temp->val=-1;
            temp->c=str[i];
            push(temp);
        }
        i++;
    }
    display(pop(),0);
}

int main()
{
    int ch=0,val=0;
    char str[100];
    printf("\nEnter any infix Expression: ");
    gets(str);

    eval(str);
}//emg
