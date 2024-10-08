#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> nse(vector<int>& a)
        {
            int n=a.size();
            stack<int> st;
            vector<int> ans(n);
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && a[i]<=st.top())
                {
                    st.pop();
                }
                ans[i]=st.empty()? -1: st.top();
                st.push(a[i]);
            }
            return ans;
        }
};

int main()
{
    vector<int> v{5,7,9,6,7,4,5,1,3,7};
    Solution obj;
    vector<int> ans= obj.nse(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";   
    }
}