#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void bitMan(int num, int i)
        {
            bool bit=(num<<i)&1; //get ith bit
            cout<<bit<<" ";
            if(bit==0) num=num|(1<<i); //set ith bit
            cout<<num<<" ";
            num=num^(1<<i); // reset ith bit
            cout<<num;
        }

};

int main()
{
    int num,i;
    cin>>num>>i;
    Solution ob;
    ob.bitMan(num,i);
}