#include<iostream>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 
  };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0;
        ListNode *curr=head;
        while(curr)
        {
            curr=curr->next;
            count++;
        }
        int trace=count/2;
        ListNode *curr2=head;
        for(int i=0;i<trace;i++)
        {
           curr2=curr2->next; 
        }
        return curr2;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};