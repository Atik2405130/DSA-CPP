#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int A[MAX];
int heapSize = 0;

// Time Complexity: O(log n) in the worst case (heap height)
void minHeapify(int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    if (left <= heapSize && A[left] < A[smallest])
    {
        smallest = left;
    }
    if (right <= heapSize && A[right] < A[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(A[i], A[smallest]);
        minHeapify(smallest);
    }
}

// Time Complexity: O(log n) in the worst case (percolate up)
void push(int value)
{
    heapSize++;
    A[heapSize] = value;
    for (int i = heapSize; i > 1; i = i / 2)
    {
        if (A[i] < A[i / 2])
        {
            swap(A[i], A[i / 2]);
        }
        else
        {
            break;
        }
    }
}

void print()
{
    for (int i = 1; i <= heapSize; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Time Complexity: O(log n) due to minHeapify call
int min_extract()
{
    if (heapSize == 0)
    {
        return -1;
    }
    int minValue = A[1];
    A[1] = A[heapSize];
    heapSize--;
    minHeapify(1);
    return minValue;
}

int main()
{
    push(20);
    push(5);
    push(15);
    push(3);
    push(10);
    print();
    cout << min_extract() << endl; // prints smallest
    print();
    cout << min_extract() << endl;
    print();
    return 0;
}