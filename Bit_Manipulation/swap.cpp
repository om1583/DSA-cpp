#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        pair<int,int> swap(int a, int b)
        {
            a^=b;
            b^=a;
            a^=b;;
            return {a,b};
        }

};
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    Solution ob;
    pair<int,int> ans=ob.swap(a,b);
    cout<<ans.first<<" "<<ans.second;
}