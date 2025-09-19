#include<bits/stdc++.h>
using namespace std;
// GFG : "https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1"
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int N = adj.size();
        int dist[N];
        for(int i = 0; i < N; i++) {
            dist[i] = 1e9;
        }
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(N, -1);
        for(int i = 0; i < N; i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};
int main() {
    //1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    int src = 0;
    Solution s;
    vector<int> ans = s.shortestPath(adj, src);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}