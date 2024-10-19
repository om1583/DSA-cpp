#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>prev(m+1,0), curr(m+1,0);;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};

int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    Solution ob;
    int ans= ob.longestCommonSubsequence(s,t);
    cout<<ans;
    return 0;
}