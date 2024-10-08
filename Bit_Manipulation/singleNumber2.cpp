#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int single2(vector<int> &nums)
        {
            sort(nums.begin(),nums.end());
            for (int i=1; i<nums.size(); i+=3)
            {
                if(nums[i]!=nums[i-1])return nums[i-1];
            } 
            return nums[nums.size()-1];
        }
};

int main()
{
    vector<int> nums{2,5,4,3,2,4,3,3,2,4};
    Solution ob;
    cout<<ob.single2(nums);
    
}