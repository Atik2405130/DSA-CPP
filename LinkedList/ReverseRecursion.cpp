#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=nullptr;
    }
};

class list
{
    public:
    Node *head;
    Node *tail;
    list()
    {
        head=tail=nullptr;
    }
    void printList()
    {
        Node *temp=head;
        while(temp)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    Node* reverse(Node *head)
    {
        if(head==NULL || head->next==NULL)return head;
        Node *newHead=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
};