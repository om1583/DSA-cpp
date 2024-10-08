#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode* next;
        ListNode(int x)
        {
            val=x;
            next=NULL;
        };
        ListNode(int x, ListNode* next1)
        {
            val=x;
            next=next1;
        };
};

void printList(ListNode* head)
{
    ListNode* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
}


class Solution {
  public:
    ListNode *odd_even(ListNode *head) {
        // Code here
        ListNode *odd=head,*even=head->next, *temp=even;
        if(head==NULL || head->next==NULL) return head;
        while (even!=NULL && even->next!=NULL)
        {
           odd->next=odd->next->next;
           even->next=even->next->next;
           
           odd=odd->next;
           even=even->next;
        }
        odd->next=temp;
        return head;
    }
};


int main()
{
    vector<int> v{1,6};
    ListNode* head= new ListNode(v[0]);
    ListNode* temp=head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode* newNode= new ListNode(v[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Solution ob;
    head=ob.odd_even(head);
    printList(head); 
    return 0;
}