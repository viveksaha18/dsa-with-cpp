#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        int dst = n-1;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);
        pq.push({0, src});
        dis[src]=0;
        ways[src]=1;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            long long d =  p.first;
            int node = p.second;
            for(auto it : adj[node]) {
                int v = it.first;
                int t = it.second;
                if(d+t < dis[v]) {
                    dis[v]=d+t;
                    ways[v]=ways[node];
                    pq.push({d+t, v});
                }
                else if(d+t == dis[v]) {
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
int main() {
    Solution s;
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << s.countPaths(n, roads) << endl;
    return 0;
}