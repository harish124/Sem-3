#include <stdio.h>
#include<stdlib.h>
#include "stackOperations.c"
#include <ctype.h>

int getPriority(char c)
{
    if(c=='*'||c=='/'||c=='%')
    {
        return 1;
    }
    if(c=='+'||c=='-')
    {
        return 0;
    }
}
int eval(char *str,char *target)
{
    int i=0,j=0;
    strcpy(target,"");

    while(str[i]!='\0')
    {
        if(str[i]=='(')
        {
            push(str[i]);
            i++;
        }

        else if(str[i]==')')
        {
            if(top==-1)
            {
                printf("\nInvalid expression line 1");
                exit(0);
            }
            else
            {
                while(top!=-1 && st[top]!='(')
                {
                    target[j]=pop();
                    j++;
                }
                pop();  //this pop is to remove the '(' character from the stack;
                i++;
            }
        }

        else if(isalpha(str[i]))
        {
            target[j]=str[i];
            i++;j++;
        }

        else if(str[i]=='+' ||str[i]=='-' ||str[i]=='*' ||str[i]=='/' ||str[i]=='%')
        {
            while(top!=-1 && st[top]!='(' && getPriority(st[top])>getPriority(str[i]))
            {
                target[j]=pop();
                j++;
            }
            push(str[i]);
            i++;
        }
        else
        {
            printf("Invalid Expression line 2\n");
            exit(0);
        }
    }//ewhile

    while(top!=-1 && st[top]!='(')
    {
        target[j]=pop();
        j++;
    }
    target[j]='\0';
}
int main()
{
    printf("\nEnter any Expression: ");
    char infix[100],postfix[100];

    gets(infix);
    eval(infix,postfix);

    printf("\nPostfix Expression: %s",postfix);
}
