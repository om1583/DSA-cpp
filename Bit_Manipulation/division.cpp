#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
                int divide(int dividend, int divisor)
                { 
                if (dividend == INT_MIN && divisor == -1) return INT_MAX;
                if (dividend == INT_MIN && divisor == 1) return INT_MIN;
                bool sign=true;
                if((dividend>0 && divisor<0)|| dividend<0 && divisor>0) sign= false;
                int ans=0;
                int n=abs(dividend),d=abs(divisor);
                while(n>=d)
                {
                        int ct=0;
                        while (n>=(d<<ct+1) && (ct + 1) < 32)
                        {
                            ct++;
                        }
                        ans+=(1<<ct);
                        n-=(d*(1<<ct));                
                }
                return sign? ans:-1*ans;
                }
};

int main()
{
    int dividend,divisor;
    cin>>dividend>>divisor;
    Solution ob;
    cout<<ob.divide(dividend,divisor);
    
}