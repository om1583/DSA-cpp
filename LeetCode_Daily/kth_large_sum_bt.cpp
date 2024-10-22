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

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long> pq;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;
            }
            pq.push(sum);
        }
        while(!pq.empty() && k>1)
        {
            k--;
            pq.pop();
        }
        return (pq.empty())? -1: pq.top();
    }
};

int main()
{
    vector<int> arr = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    int k= 2;

    TreeNode* root = constructTree(arr);
    
    Solution ob;
    int ans=ob.kthLargestLevelSum(root,k);
    cout<<ans;
    
    return 0;
}