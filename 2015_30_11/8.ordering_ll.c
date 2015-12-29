#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
} node;

int a[]= {1,2,7,20,15,10};
int i,n=sizeof(a)/sizeof(a[0]);

node *newhead;

void insertnode(node *head,int ele)
{
    node *ptr=head,*temp=malloc(sizeof(node));
    while(ptr->link!=NULL)ptr=ptr->link;
    ptr->link=temp;
    temp->data=ele;
    temp->link=NULL;
}

void display(node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}

void createlist(node *head)
{
    head->data=a[0];
    head->link=NULL;
    for(i=1; i<n; i++)
        insertnode(head,a[i]);
}

void recursivell(node *head)
{
    if(head==NULL)
    {
        return;
    }
    node *temp=head;
    node *tail=temp->link;
    if(tail==NULL)
    {
        newhead=head;
        return;
    }
    recursivell(tail);
    tail->link=temp;
    temp->link=NULL;
}

void minmaxordering(node *list)
{
    node *ptr;
    while( list->data<list->link->data )
    {
        ptr=list;
        list=list->link;
    }
    recursivell(list);
    ptr->link=newhead;
}

int main()
{
    node *list=malloc(sizeof(node));
    createlist(list);
    printf("\nList before ordering:\n");
    display(list);
    minmaxordering(list);
    printf("\nList after ordering:\n");
    display(list);
    return 0;
}
