#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void func(int idx,vector<int>& nums, vector<vector<int>>& ans)
        {
            if(idx==nums.size())
            {
                ans.push_back(nums);
                return;
            }
            for(int i=idx;i<nums.size();i++)
            {
                swap(nums[idx],nums[i]);
                func(idx+1,nums,ans);
                swap(nums[idx],nums[i]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> ans;
            func(0,nums,ans);
            return ans;
        }

};

int main()
{
    vector<int> nums={1,2,3};
    Solution ob;
    vector<vector<int>> result= ob.permute(nums);
    cout<<"[";
    for(int i=0;i<result.size();i++)
    {
        cout<<"[";
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<",";
        }
        cout<<"]"<<","<<endl;
    }
    cout<<"]";
    return 0;
}