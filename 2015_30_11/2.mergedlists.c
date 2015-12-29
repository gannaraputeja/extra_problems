#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
} node;

//INPUt is taken statically from global
int a[]= {0,2,10};
int b[]= {2,4,10};
int n=sizeof(a)/sizeof(a[0]),m=sizeof(b)/sizeof(b[0]);

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
    while(list!=NULL)
    {
        printf("%d\t",list->data);
        list=list->link;
    }
}

void merge(node *list1,node *list2)
{
    node *temp1=list1;
    node *mergedlist=temp1;
    if(list1->data<list2->data)
    {
        temp1=list1;
        list1=list1->link;
    }
    else
    {
        temp1=list2;
        list2=list2->link;
    }
    while( (list1!=NULL) && (list2!=NULL) )
    {
        if(list1->data<list2->data)
        {
            temp1->link=list1;
            list1=list1->link;
        }
        else
        {
            temp1->link=list2;
            list2=list2->link;
        }
        temp1=temp1->link;
    }
    if(list1!=NULL)
    {
        temp1->link=list1;
    }
    if(list2!=NULL)
    {
        temp1->link=list2;
    }
    printf("\nThe merged list :\n");
    display(mergedlist);
}

void createlist(node *list1,node *list2)
{
    int i;
    list1->data=a[0];
    list1->link=NULL;
    for(i=1; i<n; i++)
        insertnode(list1,a[i]);
    printf("\nFirst list : \n");
    display(list1);
    list2->data=b[0];
    list2->link=NULL;
    for(i=1; i<m; i++)
        insertnode(list2,b[i]);
    printf("\nSecond list : \n");
    display(list2);
    merge(list1,list2);
}

int main()
{
    node *list1=malloc(sizeof(node)),*list2=malloc(sizeof(node));
    createlist(list1,list2);
    return 0;
}
