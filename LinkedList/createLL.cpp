#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
        int val;
        ListNode* next;
    public:
    ListNode(int x)
    {
        val=x;
        next=NULL;
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

int main()
{
    ListNode* head= new ListNode(0);
    ListNode* temp=head;
    for (int i = 1; i < 5; i++)
    {
        ListNode* newNode= new ListNode(i);
        temp->next=newNode;
        temp=temp->next;
    }
    printList(head);   
    return 0;
}