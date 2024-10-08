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
    ListNode *reverseList(ListNode *head) {
        // Code here
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead= reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }
};


int main()
{
    vector<int> v{1,2,3,4};
    ListNode* head= new ListNode(v[0]);
    ListNode* temp=head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode* newNode= new ListNode(v[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Solution ob;
    head= ob.reverseList(head);
    printList(head); 
    return 0;
}