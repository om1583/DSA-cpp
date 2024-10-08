#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minBitFlips(int start, int goal)
        {
            int flip=0;
            int temp=start^goal;
            while(temp>0)
            {
                if(temp&1)flip++;
                temp>>=1;
            }
            return flip;
        }
};

int main()
{
    int start, goal;
    cin>>start>>goal;
    Solution ob;
    cout<<ob.minBitFlips(start,goal);
}