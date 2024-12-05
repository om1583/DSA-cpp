// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void bfs(vector<vector<int>>& adj,int n)
        {
            vector<int> vis(n,0);
            int start= 1;
            queue<int> q;
            q.push(start);
            vis[start]=1;
            while(!q.empty())
            {
                int curr=q.front();
                q.pop();
                cout<<curr<<" ";
                for(auto i: adj[curr])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
        }
};


int main() {
    vector<vector<int>> adj{{},{2,6},{3,4},{2},{2,5},{4,7},{1,7,8},{5,6,8},{6}};
    int nodes= adj.size();
    Solution ob;
    cout<<"BFS traversal: "<<endl;
    ob.bfs(adj,nodes);
    return 0;
}