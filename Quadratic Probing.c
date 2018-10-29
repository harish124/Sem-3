#include <stdio.h>
#include <stdlib.h>

int ht[10];
int c1=0,c2=0;
int size=10;
//Hash Formula To be Used here: h(key,index(i)) = [key%sizeOfTheArray +c1*i +c2*i^2]%sizeOfTheArray
//, i ranges from 0,1... to (size-1), c1& c2 are constants
//c1 & c2 will be given in the question itself or else take any integer value <10

void init()
{
    for(int i=0;i<10;i++)
        ht[i]=-1;

    c1=1;   //initialize the constants
    c2=3;   //just taking some random values

}//This is used to initialize the hash table

void insert(int val)
{
    int key=val%10;
    int j=0;
    int insSuccessfull=0;
    if(ht[key]==-1)
    {
        ht[key]=val;
        printf("\nVal inserted successfully\n");
    }
    else
    {
        j++;
        int i=(key%10 +c1*j+c2*j*j)%10;          //This line shows the difference b/w linear probing and quadratic probing.

        for(    ;j!=10;    i=(key%10 +c1*j+c2*j*j)%10)      //since range of j is 0 to (size-1);
        {
            if(ht[i]==-1)
            {
                ht[i]=val;
                insSuccessfull=1;
                size--;
                break;
            }

            j++;

        }
        if(insSuccessfull)
        {
            printf("\nVal inserted successfully\n");
        }
        else
        {
            printf("\nArray Overflow or\nMaximum collision for this key = %d has occurred\nVal not inserted\n",key);
        }
    }

}//eins

void display()
{
    for(int i=0;i<10;i++)
    {
        printf("%d ",ht[i]);
    }
    printf("\n");
}

int search(int val)
{
    int key=val%10;
    int j=0;
    if(ht[key]==val)
    {
        printf("\nVal found\n");
        return 1;
    }
    else
    {
        j++;
        int i=(key%10 +c1*j+c2*j*j)%10;               //This line shows the difference b/w linear probing and quadratic probing.

        for(    ;j!=10;    i=(key%10 +c1*j+c2*j*j)%10)    //since range of j is 0 to (size-1);
        {
            if(ht[i]==val)
            {
                printf("\nVal found\n");
                return 1;
            }

            j++;

        }
        printf("\nVal not found\n");
        return 0;
    }
}//esearch

void deleteVal(int val)
{
    int found=search(val);
    int j=0;
    if(found)
    {
        int key=val%10;
        if(ht[key]==val)
        {
            ht[key]=-1;
            printf("\nVal deleted successfully\n");
            return;
        }
        else
        {
            j++;
            int i=(key%10 +c1*j+c2*j*j)%10;

            for(    ;j!=10;    i=(key%10 +c1*j+c2*j*j)%10)
            {
                if(ht[i]==val)
                {
                    ht[i]=-1;
                    printf("\nVal deleted successfully\n");
                    return;
                }

                j++;

            }
        }
    }
}

int main()
{
    init();
    int ch=0,val=0;
    while(1==1)
    {
        printf("\nPress:\n1:To insert\n2:To search\n3:To display\n4:To delete\nAny other no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\nPress -1 to stop:\n");
            while(1==1)
            {
                printf("\nEnter any val: ");
                scanf("%d",&val);
                if(val==-1)
                    break;
                insert(val);
            }
            break;

        case 2:
            printf("\nEnter any val to search: ");
            scanf("%d",&val);
            search(val);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nEnter any val: ");
            scanf("%d",&val);
            deleteVal(val);
            break;

        default:exit(0);
        }
    }

}
