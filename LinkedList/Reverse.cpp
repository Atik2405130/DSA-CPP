#include<iostream>
using namespace std;
  //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode *prev;
      ListNode *head;
      ListNode *tail;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr),prev(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *next=NULL;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;
    }
    void reverse(ListNode *head,ListNode *tail)
    {
    ListNode* cur = head;
    ListNode* temp = NULL;

    // Traverse the list and swap next/prev for each node
    while (cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next; //Just Pointer direction Changing
        cur->next = temp;

        // Move to the "next" node (which is prev after swap)
        cur = cur->prev;
    }

    // After loop, temp points to the old head's prev
    if (temp != NULL)
    {
        head = temp->prev;  // new head
    }
    // Update tail as well
    tail = head;
    while (tail && tail->next != NULL)
    {
        tail = tail->next;
    }
    }
};

//Doubly Linked List
