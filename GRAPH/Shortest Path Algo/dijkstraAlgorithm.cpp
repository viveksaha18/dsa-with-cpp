#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto it : adj[node]) {
                int ajdNode = it.first;
                int edgeWeight = it.second;
                if(edgeWeight + d < dist[ajdNode]) {
                    dist[ajdNode] = edgeWeight+d;
                    pq.push({edgeWeight+d, ajdNode});
                }
            }
        }
        return dist;
    }
};
int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 5}, {1, 2, 2}, {1, 3, 1}, {2, 1, 3}, {2, 3, 9}, {2, 4, 2}, {3, 4, 4}, {4, 3, 6}};
    int src = 0;
    Solution s;
    vector<int> ans = s.dijkstra(V, edges, src);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}