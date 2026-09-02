#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int A[MAX];
int heapSize = 0;

// -------- MAX-HEAPIFY --------
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

// -------- MAXIMUM --------
int maximum()
{
    if (heapSize == 0)
        return -1;
    return A[1];
}

// -------- EXTRACT-MAX --------
int extractMax()
{
    if (heapSize < 1)
    {
        cout << "Heap Underflow\n";
        return -1;
    }
    int maxValue = A[1];
    A[1] = A[heapSize];
    heapSize--;
    maxHeapify(1);
    return maxValue;
}

// -------- INCREASE-KEY --------
void increaseKey(int i, int key)
{
    if (key < A[i])
    {
        cout << "New key is smaller\n";
        return;
    }
    A[i] = key;
    while (i > 1 && A[i / 2] < A[i])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

// -------- INSERT --------
void insert(int key)
{
    heapSize++;
    A[heapSize] = INT_MIN; // -∞ equivalent
    increaseKey(heapSize, key);
}

void print()
{
    for (int i = 1; i <= heapSize; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    insert(10);
    insert(40);
    insert(15);
    insert(30);
    insert(50);
    print();
    cout << "Maximum: " << maximum() << endl;
    cout << "Extracted: " << extractMax() << endl;
    print();
    increaseKey(2, 60); // increase value at index 2
    print();
    return 0;
}