#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem : "https://leetcode.com/problems/find-eventual-safe-states/description/"
class Solution {
public:
bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj, vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;
    
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(dfs(it, vis, pathVis, adj, check) == true) {
                check[node] = 0;
                return true;
            }
        }
        else if(pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }
    
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, pathVis, graph, check);
            }
        }
        for(int i = 0; i < V; i++) {
            if(check[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution s;
    vector<int> ans = s.eventualSafeNodes(graph);
    for(int it : ans) cout << it << " ";
    return 0;
}