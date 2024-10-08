#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> powerSet(vector<int> &nums)
        {
            int subsets=1<<nums.size();
            vector<vector<int>> ans;
            for (int n=0; n<subsets; n++)
            {
                vector<int>v;
                for (int j = 0; j <nums.size(); j++)
                {
                    if((n&(1<<j)))
                    {
                        v.push_back(nums[j]);
                    }  
                }
                ans.push_back(v);
            }
            return ans;
        }
};

int main()
{
    vector<int> nums{1,2,3,4};
    Solution ob;
    vector<vector<int>> ans= ob.powerSet(nums);
    for (int i = 0; i <ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}