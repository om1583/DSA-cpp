#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int setBit(int n) {
            int k = 0;
            while (true) 
            {
                if (((n >> k) & 1) == 0)
                {
                    n |= (1 << k);
                    break;
                }
                k++;
            }
            return n;
        }
};

int main()
{
    int num;
    cin>>num;
    Solution ob;
    cout<<ob.setBit(num);
}