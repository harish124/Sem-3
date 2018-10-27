#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct poly
{
    int coeff;
    struct poly *next;
}node;
node *genPoly1(node *poly1,int n,int poly_name)
{
    printf("\nEnter the details of poly 1:\n");
    while(n>0)
    {
        node *new_node=(node *)malloc(sizeof(node));
        if(poly_name!=3)
        {
            printf("\nEnter any value: ");
            scanf("%d",&new_node->coeff);
        }
        if(poly_name==3)
        {
            new_node->coeff=0;
        }
        if(poly1==NULL)
        {
            new_node->next=NULL;
            poly1=new_node;
        }
        else
        {
            node *ptr=poly1;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        n--;
    }
    return poly1;
}
node *genPoly2(node *poly2,int n,int poly_name)
{
    printf("\nEnter the details of poly 2:\n");
    while(n>0)
    {
        node *new_node=(node *)malloc(sizeof(node));
        if(poly_name!=3)
        {
            printf("\nEnter any value: ");
            scanf("%d",&new_node->coeff);
        }
        if(poly_name==3)
        {
            new_node->coeff=0;
        }
        if(poly2==NULL)
        {
            new_node->next=NULL;
            poly2=new_node;
        }
        else
        {
            node *ptr=poly2;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        n--;
    }
    return poly2;
}
void display(node *poly,int size)
{
    node *ptr=poly;
    while(ptr->next!=NULL)
      {
          printf("%dx^%d + ",ptr->coeff,size-1);
          ptr=ptr->next;
          size--;
      }
      printf("%d\n",ptr->coeff);
}
node* polyAdd(node*poly1,node*poly2,node*poly3,int deg1,int deg2)
{
    node *ptr1=poly1,*ptr2=poly2,*ptr3=poly3;
    while(deg1>deg2)
    {
        ptr3->coeff+=ptr1->coeff;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
        deg1--;
    }
    while(deg1<deg2)
    {
        ptr3->coeff+=ptr2->coeff;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
        deg2--;
    }
    while(deg1==deg2 &&(deg1>0&&deg2>0))
    {
        ptr3->coeff+=ptr1->coeff+ptr2->coeff;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
        deg1--;
        deg2--;
    }
    return poly3;
}
int main()
{
    node *poly1=NULL,*poly2=NULL,*poly3=NULL;
    printf("\nEnter the degree of (poly1,poly2): ");
    int size1,size2,size3;
    scanf("%d,%d",&size1,&size2);
    size1+=1;
    size2+=1;
    poly1=genPoly1(poly1,size1,1);
    poly2=genPoly2(poly2,size2,1);
    if(size1>=size2)
    {
        poly3=genPoly1(poly3,size1,3);
        size3=size1;
    }
    else
    {
        poly3=genPoly2(poly3,size2,3);
        size3=size2;
    }
    printf("\nPoly 1:\n");
    display(poly1,size1);
    printf("\nPoly 2:\n");
    display(poly2,size2);

    poly3=polyAdd(poly1,poly2,poly3,size1,size2);
    printf("\nPoly 3 after addition:\n");
    display(poly3,size3);
}
