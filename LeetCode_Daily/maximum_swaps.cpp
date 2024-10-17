#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string Num=to_string(num);
        int n= Num.size();
        int maxidx=n-1;
        int maxi=Num[n-1];
        int idx1=-1;
        int idx2=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(Num[i]>maxi)
            {
                maxi=Num[i];
                maxidx=i;
            }
            else if(Num[i]<maxi)
            {
                idx1=i;
                idx2=maxidx;
            }
            else
            {
                continue;
            }
        }
        if(idx1!=-1)swap(Num[idx1],Num[idx2]);
        num=stoi(Num);
        return num;
    }
};

int main()
{
    int num;
    cin>>num;
    Solution ob;
    int ans= ob.maximumSwap(num);
    cout<<ans;
    return 0;
}
