#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *createFromArray(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << endl;
}

int indexOf(Node *head, int val)
{
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        if (current->data == val)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

Node *getNodeAt(Node *head, int index)
{
    Node *current = head;
    int currentIndex = 0;
    while (current != nullptr)
    {
        if (currentIndex == index)
        {
            return current;
        }
        current = current->next;
        currentIndex++;
    }
    return nullptr;
}

// Insert a new node at the front of the list
Node *insertAtFront(Node *head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

// Insert a new node at the specified index
Node *insertAtIdx(Node *head, int index, int val)
{
    if (index == 0)
    {
        return insertAtFront(head, val);
    }
    Node *prev = getNodeAt(head, index - 1);
    if (prev != nullptr)
    {
        Node *newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        return head;
    }
    return head; // index out of bounds, no insertion
}

// Insert a new node at the end of the list
Node *insertAtEnd(Node *head, Node *&tail, int val)
{
    if (head == nullptr)
    {
        tail = new Node(val);
        head = tail;
        return head;
    }
    Node *newNode = new Node(val);
    tail->next = newNode;
    tail = newNode;
    return head;
}

// Remove head node
Node *removeHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Remove tail node
Node *removeTail(Node *head, Node *&tail)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
    {
        delete head;
        tail = nullptr;
        return nullptr;
    }
    Node *current = head;
    while (current->next->next != nullptr)
        current = current->next;
    delete current->next;
    current->next = nullptr;
    tail = current;
    return head;
}

Node *removeAtIdx(Node *head, int index)
{
    if (head == nullptr)
        return nullptr;
    if (index == 0)
        return removeHead(head);
    Node *prev = getNodeAt(head, index - 1);
    if (prev != nullptr && prev->next != nullptr)
    {
        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    return head;
}

// Update value at index
void updateAtIdx(Node *head, int index, int val)
{
    Node *node = getNodeAt(head, index);
    if (node != nullptr)
        node->data = val;
}

// Left rotate by n positions
Node *leftRotate(Node *head, Node *&tail, int n)
{
    if (head == nullptr || head->next == nullptr || n == 0)
        return head;
    int len = 0;
    Node *current = head;
    while (current != nullptr)
    {
        len++;
        current = current->next;
    }
    n = n % len;
    if (n == 0)
        return head;
    Node *newTail = getNodeAt(head, n - 1);
    Node *newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    tail = newTail;
    return newHead;
}

// Right rotate by n positions
Node *rightRotate(Node *head, Node *&tail, int n)
{
    if (head == nullptr || head->next == nullptr || n == 0)
        return head;
    int len = 0;
    Node *current = head;
    while (current != nullptr)
    {
        len++;
        current = current->next;
    }
    n = n % len;
    if (n == 0)
        return head;
    return leftRotate(head, tail, len - n);
}

int main()
{
    Node *n1 = new Node(21);
    Node *n2 = new Node(42);
    Node *n3 = new Node(54);
    Node *n4 = new Node(78);
    Node *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Node *tail = n4;
    return 0;
}

/*
======================================================================
LINKED LIST OPERATION TIME COMPLEXITY (SLL)
======================================================================

Operation                | Time Complexity | Notes
-------------------------|-----------------|---------------------------
Insert at Head (prepend) | O(1)            | Direct access, no search
Insert at Tail (append)  | O(1)            | With tail pointer, O(n) without
Insert at Index          | O(n)            | Must find position first
Find Node (by value)     | O(n)            | Linear search through list
Get Head                 | O(1)            | Direct access
Get Tail                 | O(1)            | With tail pointer; O(n) without
Get Node at Index        | O(n)            | Must traverse from head
Remove Head              | O(1)            | Update head pointer only
Remove Tail              | O(n)            | Must find node before tail
Remove at Index          | O(n)            | Must find node before target
Print/Traverse All       | O(n)            | Visit each node once
Get Length               | O(n)            | Must traverse entire list
*/