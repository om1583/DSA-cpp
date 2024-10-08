#include<bits/stdc++.h>
using namespace std;

string maximumOdd(string s) {
        int i=0,j=0;
        while(i<s.size())
        {
            if(s[i]=='1')
            {
                swap(s[i],s[j]);
                j++;
            }
            i++;
        }
        swap(s[i-1],s[j-1]);
        return s;
    }

int main()
{
    string s;
    cin>>s;
    s=maximumOdd(s);
    cout<<s;
    return 0;
}
