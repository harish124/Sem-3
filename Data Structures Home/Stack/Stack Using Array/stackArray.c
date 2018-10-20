#include <stdio.h>
#include<stdlib.h>

int st[100],top=-1,size=0;
void push(int val)
{
    if(top==size-1)
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
void display()
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
int main()
{
    printf("\nEnter the size of the stack:\n");
    scanf("%d",&size);
    int ch=0,val=0,temp=0;

    while(1==1)
    {
        printf("\nPress:\n1:To push\n2:To pop\n3:To display the stack\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:printf("\nEnter any val to push: ");
            scanf("%d",&val);
            push(val);
            break;

            case 2:temp=pop();
            if(temp!=-1)
            {
                printf("\nVal popped = %d\n",temp);
            }
            break;

            case 3:
                display();
                break;

            default:exit(0);
        }
    }
}
