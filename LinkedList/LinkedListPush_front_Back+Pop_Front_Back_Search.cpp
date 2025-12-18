#include<iostream>
using namespace std;

// Individual Node CLass //

class Node
{
    public:
    int data;
    Node* next;
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
            Node *current=new Node(value);
            if(head==NULL)head=tail=current; //trail upholds//
            else
            {
                current->next=head;
                head=current;
            }
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
        void printLL()
        {
            Node *temp=head;
            while(temp)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
        void pop_front()
        {
            if(head==nullptr)
            {
                cout<<"error"<<endl;
                return;
            }
            Node *temp=head;
            head=head->next;
            temp->next=nullptr;
            delete temp;
        }
        void pop_back()
        {
            if(head==NULL)return;
            if(head == tail)  // only one node
            {
                delete head;
                head = tail = NULL;
                return;
            }

            Node *temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=nullptr;
            delete tail;
            tail=temp;
        }
        void insertMiddle(int value,int pos)
        {
            Node *newNode=new Node(value);
            Node *temp=head;
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
        }
        int search(int key)
        {
            Node *temp=head;
            int idx=0;
            while(temp)
            {
                if(temp->data==key)return idx;
                else
                {
                    temp=temp->next;
                    idx++;
                }
            }
            return -1;
        }
};

int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(7); // 3 2 1
    ll.printLL();
    ll.pop_front();
    cout<<"After deleting the first element :"<<endl;
    ll.printLL();
    ll.pop_back();
    cout<<"After deleting the last element :"<<endl;
    ll.printLL();
    ll.insertMiddle(4,2);
    cout<<"After Insertion :"<<endl;
    ll.printLL();
    cout<<"Found at idx : "<<ll.search(4)<<endl;
}
