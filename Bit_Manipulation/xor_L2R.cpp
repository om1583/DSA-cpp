#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int xorN(int n)
        {
            if(n%4==1)return 1;
            else if(n%4==2)return n+1;
            else if(n%4==3)return 0;
            else if(n%4==0)return n;
        }
        int XOR(int l, int r)
        {
           return xorN(l-1)^xorN(r);
        }
};

int main()
{
    int l,r;
    cin>>l>>r;
    Solution ob;
    cout<<ob.XOR(l,r);
    
}