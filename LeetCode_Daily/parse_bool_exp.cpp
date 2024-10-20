#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<int> st;
        for(auto c:expression)
        {
            if(c=='('|| c==',')
            {
                continue;
            }
            else if(c==')')
            {
                bool t=false, f=false;
                while(st.top()!='!'&& st.top()!='&'&&st.top()!='|')
                {
                    char top= st.top();
                    st.pop();
                    if(top=='t') t=true;
                    if(top=='f') f=true;                    
                }
                char operation=st.top();
                st.pop();
                if(operation=='!') st.push(t? 'f': 't');
                else if(operation=='|') st.push(t? 't': 'f');
                else st.push(f? 'f': 't');
            }
            else
            {
                st.push(c);
            }
            
        }
        return st.top()=='t';
    }
};

int main()
{
    string experession;
    cin>>experession;
    Solution ob;
    bool ans=ob.parseBoolExpr(experession);
    if(ans)cout<<"True";
    else cout<<"False";
    return 0;
}