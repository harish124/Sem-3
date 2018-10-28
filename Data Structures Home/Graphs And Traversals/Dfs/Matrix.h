#include<stdio.h>
#include<stdlib.h>

int start=0;

void displayMat(int mat[][100],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("\n");
        for(int j= 0;j<size;j++)
        {
            printf("mat[%d][%d] = %d\t",i,j,mat[i][j]);
        }
    }
}
int setStartVertex()  //start is the variable where we are going to start from
{
    printf("\nEnter any character to start from: ");
    char ch;
    scanf(" %c",&ch);
    //printf("\nDisplaying matrix below: \n");
    //displayMat(mat);

    switch(ch)
    {
        case 'a':start=0;
        break;

        case 'b':start=1;
        break;

        case 'c':start=2;
        break;

        case 'd':start=3;
        break;

        case 'e':start=4;
        break;

        case 'f':start=5;
        break;

        case 'g':start=6;
        break;

        case 'h':start=7;
        break;

        case 'i':start=8;
        break;

        case 'j':start=9;
        break;

        case 'k':start=10;
        break;

        //Note: Add more alphabets if you have more nodes/vertices
        default:printf("\nStart set to 0 by default\n");
        break;

    }

}
int makeMatrix(int mat[][100],int size)
{

    int i=65,temp=i;
    printf("Press:\n1:If there is an edge:\n2:If there is no edge:\nAny other no. will be considered as no edge\n");
    for(i=65;i<temp+size;i++)
    {
        for(int j=65;j<temp+size;j++)
        {

            printf("%c -> %c\n",i,j);
            scanf("%d",&mat[i-65][j-65]);
        }
    }


}

