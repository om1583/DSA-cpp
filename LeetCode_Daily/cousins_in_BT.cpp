/*
    Given the root of a binary tree, replace the value of each node in the tree with the sum of all 
    its cousins' values.
    Two nodes of a binary tree are cousins if they have the same depth with different parents.
    Return the root of the modified tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

TreeNode* constructTree(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]); 
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size()) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
            i++;
        }

        if (i < arr.size()) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
            i++;
        }
    }

    return root;
}

void printTree(TreeNode* root)
{

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* node= q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            cout<<node->val<<" ";
        }
    }
}

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
       queue<TreeNode*> q;
       vector<int> sums;
       q.push(root);
       while(!q.empty())
       {
            int size= q.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
            }
            sums.push_back(sum);
       }

       q.push(root);
       root->val=0;
       int idx=1;
       while(!q.empty())
       {
            int size= q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();

                int siblingSum =(node->left ?node->left->val : 0) +     (node->right ? node->right->val : 0);
                
                if(node->left)
                {
                    node->left->val=sums[idx]-siblingSum;
                    q.push(node->left);
                }
                if(node->right)
                {
                    node->right->val=sums[idx]-siblingSum;
                    q.push(node->right);
                }

            }
            idx++;
       }
       return root;
    }
};

int main()
{
    vector<int> arr = {5,4,9,1,10,7,8};
    int k= 2;

    TreeNode* root = constructTree(arr);
    
    Solution ob;
    TreeNode* ans=ob.replaceValueInTree(root);
    printTree(ans);
    return 0;
}