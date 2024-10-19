#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BitOr(int idx, int Or, int n, vector<int>& nums, map<int,int>& mp)
    {
        if(idx==n)
        {
            mp[Or]++;
            return;
        }
        BitOr(idx+1,Or|nums[idx],n,nums,mp);
        BitOr(idx+1,Or,n,nums,mp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        map<int,int> mp;
        int n= nums.size();
        BitOr(0,0,n,nums,mp);
        int maxOr=INT_MIN;
        for(auto it: mp)
        {
            maxOr=max(it.second,maxOr);
        }
        return maxOr;
    }
};

int main()
{
    vector<int> nums={3,2,1,5};
    Solution ob;
    int ans=ob.countMaxOrSubsets(nums);
    cout<<ans;
    return 0;
}