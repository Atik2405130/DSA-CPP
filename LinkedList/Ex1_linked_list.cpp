#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

KEY INSIGHTS:
- Singly linked lists excel at head operations (O(1))
- Tail operations require maintaining a tail pointer for efficiency
- Any search-based operation is O(n) since we must traverse
- No random access like arrays (no O(1) index access)
======================================================================
*/

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

// Create a linked list from an array
Node *createFromArray(int arr[], int n)
{
    if (n <= 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Print a linked list from its head
void printLinkedList(Node *head)
{
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << "->";
        current = current->next;
    }

    cout << "NULL" << endl;
}

// Free all nodes of the linked list
void freeLinkedList(Node *head)
{
    Node *current = head;

    while (current != nullptr)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

// Get index of a node containing value, -1 if not found
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

// Return node located at index, nullptr if out of bounds
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
    return newNode; // New head
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
    {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    tail = current;

    return head;
}

// Remove node at the specified index
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
    {
        node->data = val;
    }
}

// Reverse the linked list recursively
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *newHead = reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
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
    cout << "=== Linked List Operations Testing ===" << endl
         << endl;

    // Test 1: Create from array
    cout << "1. Create from array [15, 42, 10, 5, 19]:" << endl;
    int arr[5] = {15, 42, 10, 5, 19};

    Node *head = createFromArray(arr, 5);
    Node *tail = getNodeAt(head, 4);

    printLinkedList(head);

    // Test 2: Insert at front
    cout << "2. Insert 100 at front:" << endl;
    head = insertAtFront(head, 100);
    printLinkedList(head);

    // Test 3: Insert at index
    cout << "3. Insert 50 at index 2:" << endl;
    head = insertAtIdx(head, 2, 50);
    printLinkedList(head);

    // Test 4: Insert at end
    cout << "4. Insert 1 at end:" << endl;
    head = insertAtEnd(head, tail, 1);
    printLinkedList(head);

    // Test 5: indexOf
    cout << "5. Find index of value 42:" << endl;
    cout << "   Index: " << indexOf(head, 42) << endl;
    cout << "   Index of 999 (not found): " << indexOf(head, 999) << endl;

    // Test 6: getNodeAt
    cout << "6. Get node at index 3:" << endl;
    Node *node = getNodeAt(head, 3);

    if (node)
        cout << "   Value: " << node->data << endl;
    else
        cout << "   Out of bounds" << endl;

    // Test 7: remove head
    cout << "7. Remove head:" << endl;
    head = removeHead(head);
    printLinkedList(head);

    // Test 8: remove tail
    cout << "8. Remove tail:" << endl;
    head = removeTail(head, tail);
    printLinkedList(head);

    // Test 9: remove at index
    cout << "9. Remove node at index 2:" << endl;
    head = removeAtIdx(head, 2);
    printLinkedList(head);

    // Test 10: update at index
    cout << "10. Update index 1 to 999:" << endl;
    updateAtIdx(head, 1, 999);
    printLinkedList(head);

    // Test 11: reverse linked list
    cout << "11. Reverse linked list:" << endl;
    head = reverse(head);
    tail = getNodeAt(head, 4);
    printLinkedList(head);

    // Test 12: left rotate
    cout << "12. Left rotate by 2:" << endl;
    head = leftRotate(head, tail, 2);
    printLinkedList(head);

    // Test 13: right rotate
    cout << "13. Right rotate by 2:" << endl;
    head = rightRotate(head, tail, 2);
    printLinkedList(head);

    // Test 14: Clean up
    cout << "14. Freeing memory..." << endl;
    freeLinkedList(head);
    cout << "Done!" << endl;

    return 0;
}