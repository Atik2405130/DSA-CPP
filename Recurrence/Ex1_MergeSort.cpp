#include <iostream>
#include <cstdlib>
#include <ctime>

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

void printArray(int *arr, int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

bool isSorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 20;

    int *arr = new int[n];
    srand(123); // deterministic seed

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (n / 10 + 1); // avoid division by 0 for small n
    }

    cout << "Before sorting (n=" << n << "):" << endl;
    printArray(arr, n);

    mergesort(arr, 0, n);

    cout << "\nAfter sorting:" << endl;
    printArray(arr, n);

    if (isSorted(arr, n))
    {
        cout << "\n✓ Array is correctly sorted!" << endl;
    }
    else
    {
        cout << "\n✗ ERROR: Array is NOT sorted!" << endl;
    }

    delete[] arr;
    return 0;
}