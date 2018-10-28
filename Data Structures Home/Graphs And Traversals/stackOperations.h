#include <stdio.h>
#include<stdlib.h>



int st[100],top=-1,Stsize=0;

void push(int val)

{

    if(top==Stsize-1)

    {

        printf("\nStack overflow!!!!\nVal not inserted\n");

        return ;

    }

    else

    {

        st[++top]=val;

    }

}//epush



int pop()

{

    if(top==-1)

    {

        printf("\nStack underflow\n");

        return -1;

    }

    else

    {

        return st[top--];

    }

}

void displayStack()

{

    if(top==-1)

    {

        printf("\nStack underflow\n");

        return ;

    }

    for(int i=0;i<=top;i++)

    {

        printf("%d ",st[i]);

    }

    printf("\n");

}


