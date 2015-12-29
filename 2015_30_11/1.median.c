#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
}node;

void insertnode(node *head,int ele)
{
    node *ptr=head,*temp=malloc(sizeof(node));
    while(ptr->link!=NULL)ptr=ptr->link;
    ptr->link=temp;
    temp->data=ele;
    temp->link=NULL;
}

void list(node *head)
{
    float medianvalue;
    int a[]={1,2,3,4,5,6,7,8};
    int i,size,n=sizeof(a)/sizeof(a[0]);
    head->data=a[0];
    head->link=NULL;
    for(i=1;i<n;i++)
        insertnode(head,a[i]);  //Taking the data in to linked list statically
    size=median(head);
    if(size%2==0)               //if number of nodes  are even
        medianvalue=(float)(a[size/2]+a[size/2-1])/2;
    else                           //if number of nodes are odd
        medianvalue=a[size/2];
    printf("\nMedian for the given linked list is : %f",medianvalue);
}

int median(node *head)
{
    node *temp=head;
    int size=0;
    for(;temp!=NULL;temp=temp->link)
        size++;                         //calculating number of nodes
    return size;
}

int main()
{
    node *head=malloc(sizeof(node));
    list(head);
    return 0;
}
