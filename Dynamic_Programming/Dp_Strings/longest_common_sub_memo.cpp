#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSub(int i1, int i2, string& text1, string& text2, vector<vector<int>>& dp)
    {
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(text1[i1]==text2[i2])
        {
            return dp[i1][i2]= 1+ longestSub(i1-1,i2-1,text1,text2,dp);
        }
        return dp[i1][i2]= max(longestSub(i1-1,i2,text1,text2,dp),longestSub(i1,i2-1,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return longestSub(n-1,m-1,text1,text2,dp);
    }
};

int main()
{
    string text1, text2;
    cin>>text1;
    cin>>text2;
    Solution ob;
    int ans= ob.longestCommonSubsequence(text1,text2);
    cout<<ans;
    return 0;
}