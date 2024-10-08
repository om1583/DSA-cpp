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

    bool check(ListNode *head1, ListNode *head2) {
        // Code here
        while(head1!=NULL && head2!= NULL)
        {
            if(head1->val!=head2->val)return false;
        }
        return true;
    }

    ListNode *mid(ListNode *head) {
        // using tortoise and hare algorithm
        if(head==NULL || head->next== NULL) return head;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode *head) {
        // Code here
        ListNode* middle=mid(head);
        ListNode* half= reverseList(middle->next);
        bool ans=check(head,half);
        return ans;
    }
};


int main()
{
    vector<int> v{1,2,2,1};
    ListNode* head= new ListNode(v[0]);
    ListNode* temp=head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode* newNode= new ListNode(v[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Solution ob;
    cout<<ob.isPalindrome(head);
    //printList(head);
    return 0;
}