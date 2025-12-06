//Section A

#include<stdio.h>
int main()
{
    int stocks[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=9;
    int p=0;
    for(int start=0;start<n;start++)
    {
        int cursum=0;
        for(int end=start;end<n;end++)
        {
            cursum+=stocks[end];
            if(cursum>p)p=cursum;
        }      
    }
    printf("%d",p);
}

//Section B
int main()
{
    int scores[]={4,-1,-3, 2,-2,0};
    int n=6;
    int flag;
    int i;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(int j=i+1;j<n;j++)
        {
            if(scores[i]>scores[j])flag=1;
            else flag=0;
        }
        if(flag)printf("%d ",scores[i]);
    }
    printf("%d",scores[i]);
}

//Section C

int main()
{
    int votes[]={1,2,3,2,3,1,2};
    int n=7;
    int count=0;
    int m;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=i+1;j<n;j++)
        {
            if(votes[i]==votes[j])c++;
        }
        if(c>count)
        {
            count=c;
            m=votes[i];
        }
    }
    if(count==1)printf("No majority element");
    else
    printf("%d",m);
}