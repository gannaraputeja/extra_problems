#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
}node;

int a[]={1,2,3,4,5,6,7,8},n=sizeof(a)/sizeof(a[0]);

void insertnode(node *head,node *tail,int ele)
{
    node *ptr=head,*temp=malloc(sizeof(node));
    while(ptr->link!=head)ptr=ptr->link;
    ptr->link=temp;
    temp->data=ele;
    temp->link=head;
    tail=temp;
}

void display(node *head,node *tail)
{
    node *ptr=head;
    while(ptr->link!=tail)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("%d\t",ptr->data);
}

void list(node *head,node *tail)
{
    int ele;
    int i;
    head->data=a[0];
    head->link=head;
    tail=head;
    for(i=1;i<n;i++)
        insertnode(head,tail,a[i]);  //Taking the data in to linked list statically
    printf("\ncircular list before inserting a node\n");
    display(head,tail);
    printf("\nEnter the element value to be inserted in to circular linked list : ");
    scanf("%d",&ele);
    insertnode(head,tail,ele);
    printf("\ncircular list before inserting a node\n");
    display(head,tail);
}

int main()
{
    node *head=malloc(sizeof(node)),*tail=malloc(sizeof(node));
    list(head,tail);
    return 0;
}
