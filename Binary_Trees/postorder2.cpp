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
    vector<int> postorder(Node* root)
    {
       vector<int> ans;
       if (root == NULL) return ans;
       
       stack<Node*> st1, st2;
       st1.push(root);
       
       while (!st1.empty())
       {
           Node* curr = st1.top();
           st1.pop();
           st2.push(curr);
           
           if (curr->left) st1.push(curr->left);
           if (curr->right) st1.push(curr->right);
       }
       
       while (!st2.empty())
       {
           ans.push_back(st2.top()->val);
           st2.pop();
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
    vector<int> ans=ob.postorder(root);
    for(int i=0; i<ans.size();i++)
    {
        cout<<ans[i]<<"->";
    }
    return 0;
}