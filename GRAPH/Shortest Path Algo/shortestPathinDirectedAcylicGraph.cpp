#include<bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution {
  public:
  void dfs(int node, stack<int>& st, vector<vector<int>>& adj, vector<int>& vis) {
      vis[node] = 1;
      for(auto it : adj[node]) {
          if(!vis[it]) {
              dfs(it, st, adj, vis);
          }
      }
      st.push(node);
  }
    stack<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        stack<int> st;
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, st, adj, vis);
            }
        }
       return st;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }
        stack<int> st =  topoSort(V, edges);
        vector<int> dist(V, 1e9);
        dist[0]=0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto it : adj[node]) {
                int n = it.first;
                int wt = it.second;
                if(dist[n] > dist[node]+wt) {
                    dist[n] = dist[node]+wt;
                }
            }
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
int main() {
    Solution s;
    int V = 6, E = 7;
    vector<vector<int>> edges = {{0,1,2},{0,4,1},{1,2,3},{4,2,2},{4,5,4},{2,3,6},{5,3,1}};
    vector<int> res = s.shortestPath(V, E, edges);
    for(auto it : res) {
        cout << it << " ";
    }
    return 0;
}