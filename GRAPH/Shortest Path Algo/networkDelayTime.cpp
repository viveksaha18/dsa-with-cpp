#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }
        int src = k;
        pq.push({0, src});
        vector<int> dis(n+1, 1e9);
        dis[src]=0;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            for(auto it : adj[node]) {
                int v = it.first;
                int t = it.second;
                if(dis[v] > d+t) {
                    dis[v]=d+t;
                    pq.push({d+t, v});
                }
            } 
        }
        for(int i = 0; i < dis.size(); i++) {
            if(i == 0) continue;
            if(dis[i] == 1e9) return -1;
        }
        int maxi = -1;
        for(int i = 1; i < dis.size(); i++) maxi=max(maxi, dis[i]);
        return maxi;
    }
};
int main() {
    Solution s;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout << s.networkDelayTime(times, n, k) << endl;
    return 0;
}