/* Split string into maximum number of unique substrings
e.g "ababccc" op->5
One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. 
Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int idx, int n, int& maxi, string& s, set<string>& st)
    {
        if(idx==n)
        {
            maxi=max(maxi,(int)st.size());
        }
        for(int i=idx;i<n;i++)
        {
            string sub= s.substr(idx,i-idx+1);
            if(st.find(sub)==st.end())
            {
                st.insert(sub);
                backtrack(i+1,n,maxi,s,st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n=s.size();
        set<string> st;
        int maxi=0;
        backtrack(0,n,maxi,s,st);
        return maxi;
    } 
};

int main()
{
    string s;
    cin>>s;
    Solution ob;
    int ans= ob.maxUniqueSplit(s);
    cout<<ans;
    return 0;
}