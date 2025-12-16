#include<iostream>
using namespace std;

// Individual Node CLass //

class Node
{
    public:
    int data;
    Node* next;
    //public:
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
        List(){
            head=tail=NULL;
        }
        void push_front(int value)
        {
            Node *newNode=new Node(value);
            if(head==NULL)head=tail=newNode;
            else
            {
                newNode->next=head;
                head=newNode;
            }
        }
        void printLL()
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
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3); // 3 2 1
    ll.printLL();
}
