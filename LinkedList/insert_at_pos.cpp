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
    ListNode *insertPos(ListNode *head, int pos, int val ) {
        // Code here
        if(head==NULL || pos==1) //edge case to handle if list is null or insertion at head;
        {
            ListNode* newNode= new ListNode(val,head);
            return newNode;
        }
        ListNode* temp=head;
        while(pos-- && temp->next!=NULL)
        {
            temp=temp->next;
        }
        ListNode* newNode= new ListNode(val,temp->next);
        temp->next=newNode;
        return head;
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
    head= ob.insertPos(NULL,1,7);
    printList(head); 
    return 0;
}