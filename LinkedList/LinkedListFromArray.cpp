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
};

Node *createFromArray(int arr[],int n)
{
    Node *head=new Node(arr[0]);
    Node *current=head;
    for(int i=1;i<n;i++)
    {
        current->next=new Node(arr[i]);
        current=current->next;
    }
    return head;
}

int main()
{
    int arr[]={21,43,31,10};
    int n=4;
    list ll;
    ll.head=createFromArray(arr,n);
    ll.printList();

}

