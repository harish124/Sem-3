#include<stdio.h>
#include<stdlib.h>

typedef struct node
{

    int val;
    struct node *next;
}node;
node *hd=NULL;

node *makeNode(int val)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->val=val;

    return temp;
}//emake

void display(node *hd)
{
    if(hd==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    node *ptr=hd;
    while(ptr->next!=hd)
    {
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("%d \n",ptr->val);
}//edisplay

node *createList(node *hd)
{
    int val=0;
    printf("\nEnter -1 to stop\n");
    while(val!=-1)
    {
        printf("\nEnter any val to insert: ");
        scanf("%d",&val);
        if(val==-1)
        {
            break;
        }
        node *new_node =makeNode(val);

        if(hd==NULL)
        {
            new_node->next=new_node;    //this step is crucial
            hd=new_node;
        }
        else
        {
            node *ptr=hd;
            while(ptr->next!=hd)
                ptr=ptr->next;

            ptr->next=new_node;
            new_node->next=hd;
        }
    }
    return hd;

}//ecreate

node *ins_beg(node *hd)
{
    int val=0;
    printf("\nEnter any val to insert: ");
    scanf("%d",&val);
    node *new_node=makeNode(val);

    if(hd==NULL)
        return new_node;
    else
    {
        node *ptr=hd;
        new_node->next=hd;
        while(ptr->next!=hd)
            ptr=ptr->next;
        ptr->next=new_node;
        hd=new_node;
    }
    return hd;
}//einsend

node *ins_end(node *hd)
{
    int val=0;
    printf("\nEnter any val to insert: ");
    scanf("%d",&val);
    node *new_node=makeNode(val);
    new_node->next=new_node;
    if(hd==NULL)
        return new_node;
    else
    {
        node *ptr=hd;
        while(ptr->next!=hd)
            ptr=ptr->next;

        ptr->next=new_node;
        new_node->next=hd;
    }
    return hd;
}//einsend

node *ins_after(node *hd)
{
    if(hd==NULL)
    {
        printf("\nThat function not available\nTry creating the list first\n");
        return hd;
    }
    int val=0,search=0;
    printf("\nEnter any val to insert: ");
    scanf("%d",&val);
    printf("\nEnter the val of the node after which to insert: ");
    scanf("%d",&search);
    node *new_node=makeNode(val);
    new_node->next=new_node;

    node *ptr=hd;
    while(ptr->next!=hd && ptr->val!=search)
        ptr=ptr->next;
    if(ptr->val==search)
    {
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    else
    {
        printf("\nSearch element not found\n");
    }

    return hd;
}//einsafter

node *del_beg(node *hd)
{
    if(hd==NULL)
    {
        printf("\nEmpty List\n");
        return hd;
    }
    else
    {
        node *ptr=hd;
        while(ptr->next!=hd)
            ptr=ptr->next;
        ptr->next=hd->next;
        free(hd);
        hd=ptr->next;
        return hd;
    }
}//edelbeg

node *del_end(node *hd)
{
    if(hd==NULL)
    {
        printf("\nEmpty List\n");
        return hd;
    }
    else
    {
        node *ptr=hd,*preptr=hd;
        while(ptr->next!=hd)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=hd;
        free(ptr);
        return hd;
    }
}//edelend

node *del_after(node *hd)
{
    if(hd==NULL)
    {
        printf("\nEmpty List\n");
        return hd;
    }
    int val=0;
    printf("\nEnter any val to delete: ");
    scanf("%d",&val);

    node *ptr=hd,*preptr=hd;

    while(ptr->next!=hd &&ptr->val!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr->val!=val)
    {
        printf("\nNo such val found\n");
        return hd;
    }
    else
    {
        preptr->next=ptr->next;
        if(ptr==hd)
        {
            free(ptr);
            return NULL;
        }
        free(ptr);
        return hd;
    }


}//edelafter

node *delList(node *hd)
{
    if(hd==NULL)
    {
        printf("\nEmpty List\n");
        return NULL;
    }
    else
    {
        node *ptr=hd;
        while(ptr->next!=hd)
            hd=del_end(hd);
        free(hd);
        return NULL;
    }
}//edelList

int main()
{

    int ch=0;
    while(1==1)
    {
        printf("\nPress:\n1:To create\n2:To ins. at beg\n3:To display\n4:To ins. at the end\n5:To ins. after a given node\n6:To del. beg\n7:To del. end\n8:To del. after a given node\n9:To del. the entire list\nAnyother no. to exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

            case 1:hd=createList(hd);
            break;

            case 2:hd=ins_beg(hd);
            break;

            case 3:display(hd);
            break;

            case 4:hd=ins_end(hd);
            break;

            case 5:hd=ins_after(hd);
            break;

            case 6:hd=del_beg(hd);
            break;

            case 7:hd=del_end(hd);
            break;

            case 8:hd=del_after(hd);
            break;

            case 9:hd=delList(hd);
            break;

            

            default:exit(0);
        }
    }//ewhile

}
