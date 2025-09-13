#include<bits/stdc++.h>
using namespace std;
// GFG Problem Link : "https://www.geeksforgeeks.org/problems/topological-sort/1"
stack<int> st;

class Solution {
  public:

void dfs(int node, vector<vector<int>>& adj, int vis[]) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            dfs(it, adj, vis);
        }
    }
    st.push(node);
}
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        int vis[V] = {0};
        vector<vector<int>> adj(V);
       
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                dfs(i, adj, vis);
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
    int V = 4;
    Solution s;
    vector<int> ans = s.topoSort(V, edges);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}