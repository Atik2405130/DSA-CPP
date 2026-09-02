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
int main()
{
    Node *n1 = new Node(1);
    return 0;
}