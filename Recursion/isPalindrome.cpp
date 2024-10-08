#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isPal2(const string &s, int start, int end)
        {
            if(start>=end)return true;
            if(s[start]!=s[end])return false;
            return isPal2(s,++start,--end);
        }

        bool isPal(string s)
        {
            string lower;
            for (char c:s)
            {
                if(isalnum(c))
                lower+=tolower(c);
            }
            return isPal2(lower,0,lower.size()-1);
        }

};

int main()
{
    string s;
    getline(cin,s);
    Solution ob;
    cout<<ob.isPal(s);
    return 0;
}