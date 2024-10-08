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
    int maxDepth(Node* root)
    {
       queue<Node*> q;
       if (root == NULL) return 0;
       q.push(root);
       int height=0;  
       while (!q.empty())
       {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
       }
       return height;
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
    cout<<ob.maxDepth(root);
    return 0;
}