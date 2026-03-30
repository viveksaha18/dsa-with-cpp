#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int c = it[2];
            adj[u].push_back({v, c});
        }
        vector<int> dis(n, 1e9);
        queue<pair<int, pair<int, int>>>q;
        // {stops, {node, dis}}
        q.push({0, {src, 0}});
        dis[src]=0;

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int s = p.first;
            int n = p.second.first;
            int c = p.second.second;
            if(s > k) continue;

            for(auto it : adj[n]) {
                int v = it.first;
                int ew = it.second;
                if(c+ew < dis[v] && s <= k) {
                    dis[v]=c+ew;
                    q.push({s+1, {v, c+ew}});
                }
            }
        }


        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0;
    int dst = 2;
    int k = 1;
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}