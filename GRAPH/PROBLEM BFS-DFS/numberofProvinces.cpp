#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem Link : https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
      vis[node] = 1;
      for(auto it : adj[node]) {
          if(!vis[it]) {
            dfs(it, vis, adj);
          }
      }
  }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};
int main() {

    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    int ans = s.findCircleNum(isConnected);
    cout << ans << endl;
    
    return 0;
}