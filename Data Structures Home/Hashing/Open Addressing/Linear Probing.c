#include <stdio.h>
#include <stdlib.h>

int ht[10];

//Hash Formula To be Used here: h(key,index(i)) = [ (key+i)%sizeOfTheArray ] , i ranges from 0 to (size-1)

void init()
{
    for(int i=0;i<10;i++)
        ht[i]=-1;
}//This is used to initialize the hash table

void insert(int val)
{
    int key=val%10;
    int insSuccessfull=0;
    if(ht[key]==-1)
    {
        ht[key]=val;
        printf("\nVal inserted successfully\n");
    }
    else
    {
        for(int i=(key+1)%10;i!=key;i=(i+1)%10)    //The increment formula used here is the same as the one used in circular queue.
        {                                          //Note i= (key+1)%10 is used because if key = 9 then ht[9+1] does not exist.
            if(ht[i]==-1)
            {
                ht[i]=val;
                insSuccessfull=1;
                break;
            }
        }
        if(insSuccessfull)
        {
            printf("\nVal inserted successfully\n");
        }
        else
        {
            printf("\nArray Overflow\nVal not inserted\n");
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

    if(ht[key]==val)
    {
        printf("\nVal found\n");
        return 1;
    }
    else
    {
        for(int i=(key+1)%10;i!=key;i=(i+1)%10)    //Note (key+1)%10 is used because if key = 9 then ht[9+1] does not exist.
        {
            if(ht[i]==val)
            {
                printf("\nVal found\n");
                return 1;
            }
        }
        printf("\nVal not found\n");
        return 0;
    }
}//esearch

void deleteVal(int val)
{
    int found=search(val);
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
            for(int i=(key+1)%10;i!=key;i=(i+1)%10)     //Note i= (key+1)%10 is used because if key = 9 then ht[9+1] does not exist.
            {
                if(ht[i]==val)
                {
                    ht[i]=-1;
                    printf("\nVal deleted successfully\n");
                    return;
                }
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
