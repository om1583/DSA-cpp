// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
        {
            cout<<node<<" ";
            vis[node]=1;
            for(auto i: adj[node])
            {
                if(!vis[i])
                {
                    dfs(i,adj,vis);
                }
            }
        }
};


int main() {
    vector<vector<int>> adj{{},{2,6},{3,4},{2},{2,5},{4,7},{1,7,8},{5,6,8},{6}};
    int n= adj.size();
    int start=1;
    vector<int> vis(n,0);
    Solution ob;
    cout<<"DFS traversal: "<<endl;
    ob.dfs(start,adj,vis);
    return 0;
}