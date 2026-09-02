#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
DOUBLY LINKED LIST OPERATION TIME COMPLEXITY

Operation                     | Time Complexity | Notes
---------------------------------------------------------------
Insert at Head                | O(1)            | Direct access via head pointer
Insert at Tail                | O(1)            | Direct access via tail pointer
Insert at Index               | O(n)            | Must traverse to position
Find Node (by value)          | O(n)            | Linear search through list
Get Head                      | O(1)            | Direct access
Get Tail                      | O(1)            | Direct access
Get Node at Index             | O(n)            | Must traverse from head/tail
Remove at Head                | O(1)            | Update head pointer only
Remove at Tail                | O(1)            | Update tail pointer only
Remove at Index               | O(n)            | Must find node to remove
Print Forward/Backward        | O(n)            | Visit each node once
*/

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node *head = nullptr;
Node *tail = nullptr;

void createFromArray(int arr[], int n)
{
    if (n == 0)
        return;
    head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = current->next;
    }
    tail = current;
}

void insertAtFront(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node *getNodeAt(int index)
{
    if (index < 0)
        return nullptr;
    Node *curr = head;
    int i = 0;
    while (curr != nullptr && i < index)
    {
        curr = curr->next;
        ++i;
    }
    return curr;
}

void insertAtIdx(int index, int val)
{
    if (index == 0)
    {
        insertAtFront(val);
        return;
    }
    Node *prev = getNodeAt(index - 1);
    if (prev == nullptr)
        return;
    if (prev->next != nullptr)
    {
        Node *newNode = new Node(val);
        newNode->next = prev->next;
        newNode->prev = prev;
        prev->next->prev = newNode;
        prev->next = newNode;
    }
    else
    {
        insertAtEnd(val);
    }
}

// remove first node
void removeAtFront()
{
    if (head == nullptr)
        return;
    Node *temp = head;
    if (head == tail) // only one node
    {
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

// remove last node
void removeAtEnd()
{
    if (tail == nullptr)
        return;
    Node *temp = tail;
    if (head == tail) // only one node
    {
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

// Remove at index
void removeAtIdx(int index)
{
    if (index == 0)
    {
        removeAtFront();
        return;
    }
    Node *temp = getNodeAt(index);
    if (temp == nullptr)
        return;
    temp->prev->next = temp->next;
    if (temp != tail)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        tail = temp->prev;
    }
    delete temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    createFromArray(arr, 4);

    cout << "Forward: ";
    for (Node *p = head; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << '\n';

    cout << "Backward: ";
    for (Node *p = tail; p != nullptr; p = p->prev)
        cout << p->data << ' ';
    cout << "\n";

    insertAtFront(0);
    insertAtEnd(5);
    insertAtIdx(3, 99);

    cout << "After inserts (forward): ";
    for (Node *p = head; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << "\n";

    removeAtFront();
    removeAtEnd();
    removeAtIdx(2);

    cout << "After removes (forward): ";
    for (Node *p = head; p != nullptr; p = p->next)
        cout << p->data << ' ';
    cout << "\n";

    return 0;
}