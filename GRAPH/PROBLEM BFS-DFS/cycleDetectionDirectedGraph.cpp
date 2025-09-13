#include<bits/stdc++.h>
using namespace std;
// GFG Problem Link : "https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1"
class Solution {
  public:
bool dfs(int node, int vis[], int pathVis[], vector<vector<int>>& adj) {
    vis[node] = 1;
    pathVis[node] = 1;
    
    
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(dfs(it, vis, pathVis, adj) == true) return true;
        }
        else if(pathVis[it]) return true;
    }
    
    
    pathVis[node] = 0;
    return false;
}
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int vis[V] = {0};
        int pathVis[V] = {0};
        vector<vector<int>> adj(V);
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                if(dfs(i, vis, pathVis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    int V = edges.size();
    Solution s;
    bool ans = s.isCyclic(V, edges);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}