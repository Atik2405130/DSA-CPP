#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    // public:
        Node(int value)
        {
            data=value;
            next=nullptr;
        }
};
class List
{
    Node *head;
    Node *tail;
    public:
    List()
    {
        head=nullptr;
        tail=nullptr;
    }
    void push_back(int value)
    {
        Node *n2=new Node(value);
        if(head==NULL)head=tail=n2;
        else
        {
            tail->next=n2;
            tail=n2;
        }
    }
    void printList()
    {
        Node *temp=head;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    List ll;
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.printList();
}
