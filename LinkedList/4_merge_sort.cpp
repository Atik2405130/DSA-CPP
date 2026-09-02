#include <bits/stdc++.h>
using namespace std;

void merge(int *ara, int lo, int mid, int hi)
{
    int *merged = new int[hi - lo];
    int left = lo, right = mid, k = 0;
    // Merge the two sorted halves
    while (left < mid && right < hi)
    {
        if (ara[left] < ara[right])
        {
            merged[k++] = ara[left++];
        }
        else
        {
            merged[k++] = ara[right++];
        }
    }
    // Copy remaining elements from left half
    while (left < mid)
    {
        merged[k++] = ara[left++];
    }
    // Copy remaining elements from right half
    while (right < hi)
    {
        merged[k++] = ara[right++];
    }
    // Copy merged array back to original
    for (int idx = 0; idx < hi - lo; idx++)
    {
        ara[lo + idx] = merged[idx];
    }
    delete[] merged;
}

void mergesort(int *ara, int lo, int hi)
{
    if (hi - lo <= 1)
    {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    mergesort(ara, lo, mid);
    mergesort(ara, mid, hi);
    merge(ara, lo, mid, hi);
}

int main()
{
    return 0;
}