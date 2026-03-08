#include <iostream>
using namespace std;

// Time complexity O(nlog(n))
//  Space complexity O(n)
//  Function to merge two sorted subarrays
void merged(int arr[], int lo, int mid, int hi)
{
    int *merge = new int[hi - lo]; // Temporary array for merged elements
    int left = lo;
    int right = mid;
    int k = 0;

    // Merge the two halves
    while (left < mid && right < hi)
    {
        if (arr[left] < arr[right])
        {
            merge[k++] = arr[left++];
        }
        else
        {
            merge[k++] = arr[right++];
        }
    }

    // Copy the remaining elements of the left half
    while (left < mid)
    {
        merge[k++] = arr[left++];
    }

    // Copy the remaining elements of the right half
    while (right < hi)
    {
        merge[k++] = arr[right++];
    }

    // Copy the sorted elements back to the original array
    for (int idx = 0; idx < hi - lo; idx++)
    {
        arr[idx + lo] = merge[idx];
    }
    delete[] merge; // Clean up the temporary array
}

// MergeSort function
void mergesort(int arr[], int lo, int hi)
{
    if (hi - lo <= 1)
    {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    mergesort(arr, lo, mid);  // Sort the left half
    mergesort(arr, mid, hi);  // Sort the right half
    merged(arr, lo, mid, hi); // Merge the two sorted halves
}

// Main function
int main()
{
    int arr[] = {6, 4, 3, 8, 1, 5, 2, 7}; // Example array
    int size = 8;                         // Size of the array
    cout << "Unsorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Print unsorted array
    }
    cout << endl;
    mergesort(arr, 0, size); // Sort the array using mergesort
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Print sorted array
    }
    cout << endl;
    return 0;
}
#include<iostream>
using namespace std;
// Time complexity-->O(nlogn)
// 2T(n/2)+O(n)
// Space complexity-->O(n)
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
    for(int idx=0;idx<hi-lo;idx++) //for(i->lo to hi) arr[i]=merge[i-lo]
    {
        arr[idx+lo]=merge[idx];
    }
    delete[]merge;
}

