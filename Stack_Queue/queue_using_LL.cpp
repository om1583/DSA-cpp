#include<iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

    public:
        Node()
        {
            next=NULL;
        }
        Node(int x)
        {
            val=x;
            next=NULL;
        }
};

class stack{
    int n=0;
    Node  *start, *end;
    public:
    void push(int x);
    void pop();
    int top();
    int size();
};
void stack::push(int x)
{
    Node* node= new Node(x);
    if(start==NULL)start=end=node;
    else end->next=node;
    n+=1;
}

void stack::pop()
{
    if(start==NULL)end=start;
    Node* temp= start;
    start=start->next;
    delete temp;
    n-=1;
}

int stack::top()
{
    if(start==NULL && end==NULL)return -1;
    return start->val;
}

int stack::size()
{
    return n;
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
    cout<<st.top()<<endl<<"size:"<<st.size()<<endl;
}