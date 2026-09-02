#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int A[MAX];
int heapSize;

// Time Complexity: O(log n) in the worst case (heap height)
void maxHeapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= heapSize && A[left] > A[largest])
        largest = left;

    if (right <= heapSize && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

// Time Complexity: O(log n) in the worst case (heap height)
void minHeapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= heapSize && A[left] < A[smallest])
        smallest = left;

    if (right <= heapSize && A[right] < A[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(A[i], A[smallest]);
        minHeapify(smallest);
    }
}

// Time Complexity: O(n) for building heap from unordered array
void buildMaxHeap(int n)
{
    heapSize = n;
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(i);
    }
}

// Time Complexity: O(n) for building heap from unordered array
void buildMinHeap(int n)
{
    heapSize = n;
    for (int i = n / 2; i >= 1; i--)
    {
        minHeapify(i);
    }
}

// Time Complexity: O(n log n) overall (n times extract-max with O(log n) each)
void heapSort(int n)
{
    buildMaxHeap(n);
    for (int i = n; i >= 2; i--)
    {
        swap(A[1], A[i]);
        heapSize--;
        maxHeapify(1);
    }
}

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 10;
    int input[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // Copy input
    for (int i = 1; i <= n; i++)
    {
        A[i] = input[i];
    }
    cout << "Max Heap:\n";
    buildMaxHeap(n);
    print(n);
    // Reset input
    for (int i = 1; i <= n; i++)
    {
        A[i] = input[i];
    }
    cout << "Min Heap:\n";
    buildMinHeap(n);
    print(n);
    cout << "Heap sort:\n";
    heapSort(n);
    print(n);
    return 0;
}