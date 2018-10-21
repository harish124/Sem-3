#include <stdio.h>
#include<limits.h>

int heap[100],heapsize=0;


void insert(int elm)
{
    heapsize++;
    int now=heapsize; //now refers to the current index
    //We are constructing a min-heap i.e heap[1] will be the min val in the heap

    while(heap[now/2]>elm)
    {
        heap[now]=heap[now/2];
        now/=2;
    }
    heap[now]=elm;
}
int delMin()
{
    int min=heap[1],last=heap[heapsize--],now=0,child=0;
    //reducing the heapsize because we are going to delete heap[1] or overwrite it
    for(now=1;now*2<=heapsize;now=child)
    {
        child=now*2;      //child refers to the smallest of the two childs

        if(child*2!=heapsize &&heap[child]>heap[child+1])
        {
            child++;
        }

        if(last>heap[child])
        {
            heap[now]=heap[child];
        }
        else
        {
            //the elm fits there
            break;
        }
    }
    heap[now]=last;
    return min;
}
int main()
{
    int number_of_elements;
    printf("Program to demonstrate Heap:\nEnter the number of elements: ");
    scanf("%d", &number_of_elements);
    int iter, element;
    heap[0]=-10000;
    printf("Enter the elements: ");
    for (iter = 0; iter < number_of_elements; iter++) {
        scanf("%d", &element);
        insert(element);
    }
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d ", delMin());
    }
    printf("\n");
    return 0;
}
