#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestHappyString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        string ans="";
        while(!pq.empty())
        {
            pair<int,char> p=pq.top();
            int ct=p.first;
            char c= p.second;
            pq.pop();
            int n=ans.size();
            if(n>=2 && ans[n-1]==c && ans[n-2]==c)
            {
                if(pq.empty())break;
                pair<int,char> p1= pq.top();
                pq.pop();
                ans+=p1.second;
                p1.first--;
                if(p1.first>0)
                {
                    pq.push({p1.first,p1.second});
                }
            }
            else
            {
                ans+=c;
                ct--;
            }
            if(ct>0)pq.push({ct,c});
        }
        return ans;
    }
};

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    Solution ob;
    string res= ob.longestHappyString(a,b,c);
    cout<<res;
    return 0;
}