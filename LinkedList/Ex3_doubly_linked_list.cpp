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

KEY INSIGHTS:
- DLL is better than SLL for tail operations (O(1) vs O(n))
- Can traverse in both directions
- Extra memory for prev pointer (space trade-off)
- Head and tail operations are both O(1)
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

// Print the list forward
void printForward()
{
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << "<->";
        current = current->next;
    }

    cout << "NULL\n";
}

// Print the list backward
void printBackward()
{
    Node *current = tail;

    while (current != nullptr)
    {
        cout << current->data << "<->";
        current = current->prev;
    }

    cout << "NULL\n";
}

// Free all nodes of the linked list
void freeLinkedList()
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    head = tail = nullptr;
}

// Create list from array
void createFromArray(int arr[], int n)
{
    freeLinkedList();

    if (n <= 0)
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

// Insert at front
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

// Insert at end
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

// Get node at index
Node *getNodeAt(int index)
{
    if (index < 0)
        return nullptr;

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

// Find index of value
int indexOf(int val)
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

// Insert at index
void insertAtIdx(int index, int val)
{
    if (index < 0)
        return;

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

// Remove first node
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

// Remove last node
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
    if (index < 0)
        return;

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
    cout << "=== Doubly Linked List Operations Testing ===\n\n";

    // Test 1: Create from array
    cout << "1. Create from array [15, 42, 10, 5, 19]:\n";
    int arr[5] = {15, 42, 10, 5, 19};
    createFromArray(arr, 5);

    cout << "   Forward:  ";
    printForward();

    cout << "   Backward: ";
    printBackward();

    // Test 2: Insert at front
    cout << "2. Insert 100 at front:\n";
    insertAtFront(100);

    cout << "   Forward:  ";
    printForward();

    // Test 3: Insert at end
    cout << "3. Insert 1 at end:\n";
    insertAtEnd(1);

    cout << "   Forward:  ";
    printForward();

    // Test 4: Insert at index
    cout << "4. Insert 50 at index 2:\n";
    insertAtIdx(2, 50);

    cout << "   Forward:  ";
    printForward();

    // Test 5: indexOf
    cout << "5. Find index of value 42:\n";
    cout << "   Index: " << indexOf(42) << "\n";
    cout << "   Index of 999 (not found): " << indexOf(999) << "\n";

    // Test 6: getNodeAt
    cout << "6. Get node at index 3:\n";
    Node *node = getNodeAt(3);

    if (node)
        cout << "   Value: " << node->data << "\n";
    else
        cout << "   Out of bounds\n";

    // Test 7: Remove at front
    cout << "7. Remove at front:\n";
    removeAtFront();

    cout << "   Forward:  ";
    printForward();

    // Test 8: Remove at end
    cout << "8. Remove at end:\n";
    removeAtEnd();

    cout << "   Forward:  ";
    printForward();

    // Test 9: Remove at index
    cout << "9. Remove at index 1:\n";
    removeAtIdx(1);

    cout << "   Forward:  ";
    printForward();

    cout << "   Backward: ";
    printBackward();

    // Test 10: Clean up
    cout << "10. Freeing memory...\n";
    freeLinkedList();

    cout << "Done!\n";

    return 0;
}