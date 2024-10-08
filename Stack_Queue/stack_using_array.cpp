#include<iostream>
using namespace std;

class stack{
    int n=4;
    int st[4];
    int t=-1;

    public:
    void push(int x);
    void pop();
    int top();
    int size();
};
void stack::push(int x)
{
    if(t>=n-1)cout<<"Stack is full\n";
    else{
        t+=1;
        st[t]=x;
    }
}

void stack::pop()
{
    if(t==-1)cout<<"Stack is empty\n";
    else t-=1;
}

int stack::top()
{
    if(t==-1)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    return st[t];
}

int stack::size()
{
    return t+1;
}


int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.top()<<endl;
    cout<<"size: "<<st.size()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top()<<endl<<"size:"<<st.size()<<endl;

}