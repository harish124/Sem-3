#include<stdio.h>

char st[100];
int top=-1;

void push(char val)
{
    if(top==99)
    {
        printf("\nStack overflow!!!\nVal not inserted\n");
        return ;
    }
    else
    {
        st[++top]=val;
    }
}
char pop()
{

    if(top==-1)
        return -1;
    else
    {
        return st[top--];
    }
}
