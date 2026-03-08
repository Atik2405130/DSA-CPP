#include <iostream>
using namespace std;

// Overall
//  Time Complexity O(nlog(n))
//  space complexity O(log(n))

// worst case
// example 1,2,3,4,5
// O(n)+O(n-1)+O(n-2)+⋯+O(1)=O(n^2)
// Time Complexity O(nlog(n))
// space complexity O(n)

//  Partition function that selects a pivot and places it in the correct position
int partition(int arr[], int p, int r) // O(n)
{
    int x = arr[r]; // pivot element
    int i = p - 1;  // Pointer to the last element smaller than pivot //i=-1
    // smaller ones are in left part and bigger ones are in right part
    // 3, 9, 8, 1, 7
    // 1, 3, 7, 8, 9
    for (int j = p; j <= r - 1; j++) // j=4, x=7, i=1,r=4
    {
        if (arr[j] <= x)
        { // If current element is less than or equal to pivot
            i = i + 1;
            swap(arr[i], arr[j]); // Swap arr[i] with arr[j]
        }
    }
    swap(arr[i + 1], arr[r]); // Move the pivot into the correct place
    return i + 1;             // Return the pivot index
}

// QuickSort function that recursively sorts the subarrays
void quicksort(int arr[], int p, int r) // p=0, r=5
{
    if (p < r)
    {
        int q = partition(arr, p, r); // Get the pivot index
        quicksort(arr, p, q - 1);     // Recursively sort the left subarray
        quicksort(arr, q + 1, r);     // Recursively sort the right subarray
    }
}

// Utility function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 4, 3, 8, 1, 5, 2, 7}; // Example array
    int size = 8;                         // Array size

    cout << "Unsorted Array: ";
    printArray(arr, size);

    quicksort(arr, 0, size - 1); // Call QuickSort

    cout << "Sorted Array: ";
    printArray(arr, size); // Print sorted array

    return 0;
}

// Practice part

// #include<iostream>
// #include<vector>
// using namespace std;

// void quickSort(int arr[],int st,int end){
//     if(st<end){
//         int pivotIdx=partition(arr,st,end);
//         quickSort(arr,st,pivotIdx-1);
//         quickSort(arr,pivotIdx+1,end);
//     }
// }
// int partition(int arr[],int st,int end){
//     int idx=st-1;
//     int pivot=arr[end];
//     int pivotIDx=end;
//     int j;
//     for(j=st;j<pivotIDx;j++){
//         if(arr[j]<=pivot){
//             idx++;
//             swap(arr[j],arr[idx]);
//         }
//     }
//     swap(arr[j],arr[++idx]);
//     return idx;
// }
