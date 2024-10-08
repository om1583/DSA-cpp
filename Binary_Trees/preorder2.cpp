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
    vector<int> preorder(Node* root)
    {
       vector<int> ans;
       if (root == NULL) return ans;
       stack<Node*> st;
       st.push(root);
       
       while (!st.empty())
       {
           Node* curr= st.top();
           ans.push_back(curr->val);
           st.pop();
           if (curr->right) st.push(curr->right);
           if (curr->left) st.push(curr->left);
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
    vector<int> ans=ob.preorder(root);
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"->";
    }
    return 0;
}