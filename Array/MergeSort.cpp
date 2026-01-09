#include<iostream>
using namespace std;
void merged(int *arr,int lo,int hi);
void mergesort(int *arr,int lo,int hi)
{
    if(hi-lo<=1) return;
    int mid=lo+(hi-lo)/2;
    mergesort(arr,lo,mid);
    mergesort(arr,mid,hi);
    merged(arr,lo,mid,hi);
}
void merged(int *arr,int lo,int mid,int hi)
{
    int *merge=new int[hi-lo];
    int left=lo;
    int right=mid;
    int k=0;
    while(left<mid && right<hi)
    {
        if(arr[left]<arr[right])
        {
            merge[k++]=arr[left++];
        }
        else
        {
            merge[k++]=arr[right++];
        }
    }
    while(left<mid)
    {
        merge[k++]=arr[left++];
    }
    while(right<hi)
    {
        merge[k++]=arr[right++];
    }
    for(int idx=0;idx<hi-lo;idx++)
    {
        arr[idx+lo]=merge[idx];
    }
    delete[]merge;
}

