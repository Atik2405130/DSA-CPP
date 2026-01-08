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
class Queue
{
    Node *head;
    Node *tail;
    public:
    Queue()
    {
        head=tail=NULL;
    }
    void push(int value)
    {
        Node *newNode=new Node(value);
        if(head==NULL)head=tail=newNode;
        else
        {
            tail->next=newNode;
            tail=newNode;
        } 
    }
    void pop() //O(1)
    {
        if(head==NULL)return;
        Node *temp=head;
        head=head->next;
        if(head==NULL)tail=NULL;
        delete temp;
    }
    int front()
    {
        if(empty())return 1;
        else  return head->data;
    }
    bool empty()
    {
        return head==NULL;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}

// Using STL queue<int>q;
// all the works are same



