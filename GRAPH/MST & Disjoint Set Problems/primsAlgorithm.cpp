#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;
        vector<int> vis(V, 0);
        //{wt, {node, parent}}
        pq.push({0, {0, -1}});
        int sum = 0;
        while(!pq.empty()) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second.first;
            int parent = p.second.second;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it : adj[node]) {
                int v = it.first;
                int w = it.second;
                if(!vis[v])
                    pq.push({w, {v, node}});
            }
        }
        return sum;
    }
};
int main() {
    Solution s;
    int V = 5;
    vector<vector<int>> edges = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7}};
    cout << s.spanningTree(V, edges) << endl;
    return 0;
}