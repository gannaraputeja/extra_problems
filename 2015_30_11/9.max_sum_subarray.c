#include <stdio.h>
#include <stdlib.h>

int a[]= {1,2,3,5,-10,20,40};
int n=sizeof(a)/sizeof(a[0]);

void display()
{
    int i=0;
    while(i<n)
    {
        printf("%d\t",a[i++]);
    }
    printf("\n");
}

int calcsum(int start,int end)
{
    int sum=0;
    while(start<=end)
    {
        sum+=a[start++];
    }
    return sum;
}

int greater_sum_subarray()
{
    int i,j,start,end,cursum,sum,maxsum,maxstart=0,maxend=n;
    maxsum=a[0];
    for(i=0; i<n; i++)
    {
        cursum=a[i];
        for(j=n-1; j>=i; j--)
        {
            sum=calcsum(i,j);
            if(cursum<sum)
            {
                cursum=sum;
                start=i;
                end=j;
            }
        }
        if( (cursum>maxsum) && ( (end-start)<(maxend-maxstart) ) )
        {
            maxsum=cursum;
            maxstart=start;
            maxend=end;
        }
    }
    return maxsum;
}

int main()
{
    printf("\nThe array is : \n");
    display();
    printf("\nMaximum sum subarray is %d",greater_sum_subarray());
    return 0;
}
