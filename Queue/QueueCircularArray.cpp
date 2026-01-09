#include<iostream>
using namespace std;

class CircularArrayQueue
{
    int *data;
    int front;
    int rear;
    int count;
    int capacity;
    public:
    CircularArrayQueue(int cap)
    {
        capacity=cap;
        data=new int[capacity];
        front=0;
        rear=0;
        count=0;
    }
    ~CircularArrayQueue()
    {
        delete[] data;
    }
    bool isempty()
    {
        return count==0;
    }
    bool isfull()
    {
        return count==capacity;
    }
    void enqueue(int val)
    {
        if(isfull())
        {
            cout<<"Error : Queue overflow ";
            return;
        }
        data[rear]=val;
        rear=(rear+1)%capacity; //Circular Increment
        count++;
    }
    int dequeue()
    {
        if(isempty())
        {
            cout<<"Error : Queue  underflow";
            return -1;
        }
        int value=data[front];
        front=(front+1)%capacity;
        count--;
        return value;
    }
    int peek()
    {
         if(isempty())
        {
            cout<<"Error : Queue  is empty";
            return -1;
        }
        return data[front];
    }
    int size()
    {
        return count;
    }
    void print()
    {
        if(isempty())
        {
            cout<<"Error : Queue  is empty";
            return;
        }
        int idx=front;
        for(int i=0;i<count;i++)
        {
            cout<<data[idx]<<" ";
            idx=(idx+1)%capacity;
        }
        cout<<endl;
    }
};

int main()
{
    CircularArrayQueue q(5);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.print();
    q.peek();
    q.dequeue();
    q.print();
    q.print();
}