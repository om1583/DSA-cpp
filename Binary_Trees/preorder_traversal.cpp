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

class trees
{
    public:
    void preorder(Node* node)
    {
       if(node==NULL) return;

       cout<<node->val<<"->";
       preorder(node->left);
       preorder(node->right);
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

    trees tree;
    tree.preorder(root);
    return 0;
}