//Find kth bit in nth binary string || Leetcode Daily challenge 1545

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findKthBit(int n, int k) {
        //Base case: first string s1=0
        if(n==1)return '0';
        
        int size=(1<<n)-1;
        int mid=size/2+1;
        
        //If k is middle bit then it is 1;
        if(k==mid)return '1';

        //If k lies in first half of string return kth bit
        if(k<mid)return findKthBit(n-1,k);

        //when k lies in second half of string find n-kth bit and invert;    
        return findKthBit(n-1,size-k+1)=='0'?'1':'0';
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    Solution ob;
    char ans= ob.findKthBit(n,k);
    cout<<ans;
    return 0;
}