#include<bits/stdc++.h>
using namespace std;
// Problem on GFG 
// link : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


// Solution 
class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj, vector<int>& ls, int vis[]) {
      vis[node] = 1;
      ls.push_back(node);
      for(auto it : adj[node]) {
          if(!vis[it]) {
              dfs(it, adj, ls, vis);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        int vis[n] = {0};
        vector<int> ls;
        dfs(0, adj, ls, vis);
        return ls;
    }
        
};
int main() {
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    Solution s;
    vector<int> ans = s.dfs(adj);
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}