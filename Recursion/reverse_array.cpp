#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> reverseArray(vector<int> &v, int start, int end)
        {
            if(start>=end)return v;
            swap(v[start],v[end]);
            return reverseArray(v,++start,--end);
        }

};

int main()
{
    vector<int> v{1,2,3,4,5};
    Solution ob;
    v=ob.reverseArray(v,0,v.size()-1);
    for(int i=0; i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}