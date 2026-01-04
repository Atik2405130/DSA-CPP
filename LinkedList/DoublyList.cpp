#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data=value;
        next=prev=NULL;
    }
};

class DoublyList
{
    Node *head;
    Node *tail;
    public: 
        DoublyList()
        {
            head=tail=NULL;
        }
        void pushfront(int value)
        {
            Node *newNode=new Node(value);
            if(head==NULL)
            {
                head=tail=newNode;
            }
            else
            {
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
        }
        void pushback(int value)
        {
            Node *newNode=new Node(value);
            if(head==NULL)
            {
                head=tail=nullptr;
            }
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        void print()
        {
            Node *curr=head;
            while(curr!=NULL)
            {
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"NULL";
        }
        void popfront()
        {
            Node *temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
        void popback()
        {
            if(head==NULL)return;
            Node *temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }  
};

int main()
{
    DoublyList ll;
    ll.pushfront(1);
    ll.pushfront(2);
    ll.pushfront(3);
    ll.pushfront(4);
    ll.pushfront(5);
    ll.print();
    ll.pushback(6);
    ll.print();
    ll.popfront();
    ll.print();
    ll.popback();
    ll.print();
    return 0;
}