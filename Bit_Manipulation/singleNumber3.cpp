#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> single3(vector<int> &nums)
        {
            long Xor=0;
            for (int i=0; i<nums.size(); i++)
            {
                Xor^=nums[i];
            }
            int rightmost= (Xor & Xor-1) & Xor;
            int num1=0 , num2=0; 
            for (int i=0; i<nums.size(); i++)
            {
                if(nums[i]& rightmost)
                {
                    num1^=nums[i];
                }
                else
                {
                    num2^=nums[i];
                }
            } 
            return {num1,num2};
        }
};

int main()
{
    vector<int> nums{2,2,3,4,5,5};
    Solution ob;
    vector<int> ans=ob.single3(nums);
    cout<<ans[0]<<" "<<ans[1];
    
}