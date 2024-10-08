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
    ListNode *insertAtEnd(ListNode *head, int x) {
        // Code here
        ListNode* element= new ListNode(x);
        ListNode* temp=head;
        if(head==nullptr)return element;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next = element;
        return head;
    }
};


int main()
{
    vector<int> v{1,2,3,4};
    ListNode* head= new ListNode(v[0]);
    ListNode* temp=head;
    for (int i = 1; i < 4; i++)
    {
        ListNode* newNode= new ListNode(v[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Solution ob;
    head= ob.insertAtEnd(head,5);
    printList(head);   
    return 0;
}