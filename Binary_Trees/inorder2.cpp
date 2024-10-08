#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
     
    public:
    Node(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    };
};

class Solution
{
    public:
    vector<int> inorder(Node* root)
    {
       vector<int> ans;
       stack<Node*> st;
       Node* curr= root;
       while(curr!=NULL || !st.empty())
       {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr= st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
       }
       return ans;
    }
    
};

int main()
{   Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->left->right->left= new Node(6);
    
    root->right->left= new Node(7);
    root->right->right= new Node(8);
    root->right->right->left= new Node(9);
    root->right->right->right= new Node(10);

    Solution ob;
    vector<int> ans=ob.inorder(root);
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"->";
    }
    return 0;
}