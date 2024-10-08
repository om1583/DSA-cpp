#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int single(vector<int> &nums)
        {
            int ans=0;
            for (int i=0; i<nums.size(); i++)
            {
               ans^=nums[i];
            }
            return ans;
        }
};

int main()
{
    vector<int> nums{1,1,2,2,3,4,4};
    Solution ob;
    cout<<ob.single(nums);
    
}