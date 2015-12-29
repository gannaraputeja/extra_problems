#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
} node;

int a[]= {5,3,4,2,6,7},n=sizeof(a)/sizeof(a[0]);

void insertnode(node *head,int ele)
{
    node *ptr=head,*temp=malloc(sizeof(node));
    while(ptr->link!=NULL)ptr=ptr->link;
    ptr->link=temp;
    temp->data=ele;
    temp->link=NULL;
}

void display(node *list)
{
    printf("\n");
    while(list!=NULL)
    {
        printf("%d\t",list->data);
        list=list->link;
    }
}

void sortingll(node *list,node *head)
{
    printf("\nBefore sorting linked list : \n");
    display(list);
    node *before1=NULL,*before2=NULL,*temp=NULL;
    while(list->data<list->link->data)
    {
        before1=list;
        list=list->link;
    }
    temp=list;
    temp=temp->link;
    while( (temp->link!=NULL) && (temp->data<temp->link->data) )
    {
        before2=temp;
        temp=temp->link;
    }
    if( (temp->link!=NULL))
    {
        before2=temp;
        temp=temp->link;
    }
    else
    {
        before2=list;
        temp=list->link;
    }
    if(before1==NULL)
        head=temp;
    else
    {
        before1->link=temp;
    }
    node *ptr;
    if(before2==NULL)
    {
        ptr=temp->link;
        temp->link=list;
        list->link=ptr;

    }
    else
    {
        before2->link=list;
        ptr=temp->link;
        temp->link=list->link;
        list->link=ptr;

    }
    printf("\nAfter sorting linked list : \n");
    display(head);
}

void createlist(node *list)
{
    int i;
    list->data=a[0];
    list->link=NULL;
    for(i=1; i<n; i++)
        insertnode(list,a[i]);
}

int main()
{
    node *list=malloc(sizeof(node));
    node *head=malloc(sizeof(node));
    createlist(list);//static input
    head=list;
    sortingll(list,head);
    return 0;
}
