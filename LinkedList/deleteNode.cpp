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
    ListNode *deleteNode(ListNode *head, int x) {
        ListNode* temp= head;
        ListNode* pre=NULL;
        if(head==NULL || head->next== NULL) return NULL; //if LL is null or either have 1 node
        if(head->val==x)
        {
            //to handle the edge case for deleting head
            ListNode* node2delete= head;
            head=head->next;
            delete node2delete;
            return head;
        }
        while (temp!=NULL)
        {
            if(temp->val==x)
            {
                ListNode* node2delete=temp; 
                pre->next=temp->next;
                break;
            }
            pre=temp;
            temp=temp->next;
        }
        return head;
    }
};

int main()
{
    vector<int> v{1,2,3,4,5};
    ListNode* head= new ListNode(v[0]);
    ListNode* temp=head;
    for (int i = 1; i < v.size(); i++)
    {
        ListNode* newNode= new ListNode(v[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    Solution ob;
    head= ob.deleteNode(head,5);
    printList(head); 
    return 0;
}