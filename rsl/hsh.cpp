#include<bits/stdc++.h>
using namespace std;

int main()
{
    int hs[10]={0};
    map<int,int> mp;
    int a[]={1,2,3,1,4,3,2,9,5,4,5,5,0};
    for(int i=0;i<13;i++)
    {
        hs[a[i]]++;
        mp[a[i]]++;

    }
    int idx=0;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        cout<<it->first<<"->"<<it->second<<endl;
        it++;
    }
    // for(int i=0;i<10;i++)
    // {
    //     if(hs[i]>hs[idx])
    //     {
    //         idx=i;
    //     }
    // }
    // cout<<idx<<"->"<<hs[idx];
    return 0;
}