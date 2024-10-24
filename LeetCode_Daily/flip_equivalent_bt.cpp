/*
    Find kth largest level sum in the tree (not necessarily distinct).
    If there are fewer than k levels in the tree, return -1.
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

TreeNode* constructTree(vector<string>& arr) {
    if (arr.empty() || arr[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;  
    while (i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        if (i < arr.size() && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    return root;
}

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
        {
            return true;
        }
        if(root1==NULL || root2==NULL)
        {
            return false;
        }
        if(root1->val!=root2->val)
        {
            return false;
        }
        bool match= flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        if(match)return true;
        return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    }
};

int main()
{
    vector<string> arr1 = {"1", "2", "3", "4", "5", "6", "null", "null", "null", "7", "8"};
    vector<string> arr2 = {"1", "3", "2", "null", "6", "4", "5", "null", "null", "null", "null", "8", "7"};
    int k= 2;

    TreeNode* root1 = constructTree(arr1);
    TreeNode* root2 = constructTree(arr2);

    Solution ob;
    bool ans=ob.flipEquiv(root1,root2);
    cout<<ans;
    
    return 0;
}