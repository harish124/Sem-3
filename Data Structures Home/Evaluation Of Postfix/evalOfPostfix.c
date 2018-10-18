#include <stdio.h>
#include<stdlib.h>
#include "stackOperations.c"
#include <ctype.h>

int eval(char str[])
{
    int i=0,temp=0,rval=0,lval=0,val=0;
    while(str[i]!='\0')
    {
        if(isalpha(str[i]))
        {
            printf("\nEnter any val for %c: ",str[i]);
            scanf("%d",&temp);
            push(temp);
        }
        else
        {
            switch(str[i])
            {
            case '+': rval=pop();
                    lval=pop();
                    val=rval+lval;
                    push(val);
                    break;
            case '-': rval=pop();
                    lval=pop();
                    val=rval-lval;
                    push(val);
                    break;
            case '*': rval=pop();
                    lval=pop();
                    val=rval*lval;
                    push(val);
                    break;
            case '/': rval=pop();
                    lval=pop();
                    val=rval/lval;
                    push(val);
                    break;

            default:printf("\nInvalid character\n");
                    exit(0);
            }


        }


        i++;
    }//ewhile
    printf("\nFinal val = %d",pop());
}
int main()
{

    char str[100];
    printf("\nEnter any postfix expression: ");
    gets(str);

    eval(str);
}
