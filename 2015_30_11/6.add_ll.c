#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *link;
} node;

//INPUt is taken statically from global
int a[]= {1,2,3};
int b[]= {1,2,3};
int n=sizeof(a)/sizeof(a[0]),m=sizeof(b)/sizeof(b[0]);
int sum=0,carry=0;

void insertnode(node *head,int ele)
{
    node *ptr=head,*temp=malloc(sizeof(node));
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
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
    printf("\n");
}

int listsize(node *list)
{
    int size=0;
    while(list!=NULL)
    {
        list=list->link;
        size++;
    }
    return size;
}

node * iterate(node *list,int diff)
{
    while(diff)
    {
        list=list->link;
        diff--;
    }
    return list;
}

node* addll(node *list1,node *list2)
{
    if(list1==NULL)
    {
        return NULL;
    }
    node *result=malloc(sizeof(node));
    result->link=addll(list1->link,list2->link);
    sum=list1->data+list2->data+carry;
    carry=sum/10;
    sum%=10;
    result->data=sum;
    return result;
}

node * mergeresult(node *list1,node *list2,int diff)
{
    if(diff==0)
        return list1;
    if(diff==1)
    {
       list1->link=list2;
    }
    list1->link=mergeresult(list1->link,list2,diff-1);
    sum=list1->data+carry;
    carry=sum/10;
    list1->data=sum%10;
    return list1;
}

node * overflownode(node *list)
{
    node *temp=malloc(sizeof(node));
    temp->data=carry;
    temp->link=list;
    return temp;
}

void adding(node *list1,node *list2)
{
    int size1=listsize(list1);
    int size2=listsize(list2);
    int diff;
    node *result;
    if (size1==size2)
    {
        result=addll(list1,list2);
    }
    else if(size1>size2)
    {
        diff=size1-size2;
        node *temp=list1;
        result=addll(iterate(temp,diff),list2);
        result=mergeresult(list1,result,diff);
    }
    else
    {
        diff=size2-size1;
        result=addll(list1,iterate(list2,diff));
        result=mergeresult(list2,result,diff);
    }
    if(carry!=0)
    {
        result=overflownode(result);
    }
    printf("\nResultant linked list is : \n");
    display(result);
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
    adding(list1,list2);
}

int main()
{
    node *list1=malloc(sizeof(node)),*list2=malloc(sizeof(node));
    createlist(list1,list2);
    return 0;
}
