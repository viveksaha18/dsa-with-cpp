#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/is-graph-bipartite/"
class Solution {
public:
bool dfs(int node, int col, vector<int>& vis, vector<vector<int>>& graph) {
    vis[node] = col;
    for(auto it : graph[node]) {
        if(vis[it] == -1) {
            if(dfs(it, !col, vis, graph) == false) return false;
        }
        else if(vis[it] == col) return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                if(dfs(i, 0, vis, graph) == false) return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    Solution s;
    bool ans = s.isBipartite(graph);
    if(ans) cout << "true";
    else cout << "false";
    return 0;
}