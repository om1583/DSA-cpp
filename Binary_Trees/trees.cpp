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
    void printTree(Node* root)
    {
        stack<int> st;
        while(left!=NULL && right!=NULL)
        {
            st.push(right);
            st.push(root)
        }
    }
    
};

int main()
{   Node* root= new Node(0);
    root->left= new Node(1);
    root->right= new Node(2);
    root->left->left= new Node(3);
    root->left->right= new Node(4);
    root->right->left= new Node(5);
    root->right->right= new Node(6);
    return 0;
}