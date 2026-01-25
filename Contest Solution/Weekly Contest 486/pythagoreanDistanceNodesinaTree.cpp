#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, -1);
    queue<int> q;
    vis[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int x : adj[node]) {
            if(vis[x] == -1) {
                //  the next level  is previous level + 1
                vis[x] = vis[node] + 1;
                q.push(x);
            }
        }
    }
    return vis;
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int cnt = 0;
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // with respect to x distance to every node
        vector<int> distX = bfs(x, adj);
        vector<int> distY = bfs(y, adj);
        vector<int> distZ = bfs(z, adj);
        for(int i = 0; i < n; i++) {
            int dx = distX[i];
            int dy = distY[i];
            int dz = distZ[i];
            vector<int> temp = {dx, dy, dz};
            sort(temp.begin(), temp.end());
            int a = temp[0], b = temp[1], c = temp[2];
            if((long long)a*a + (long long) b*b == (long long)c*c) {
                cnt++;
            }
        }
        return cnt;
    }
};
int main() {
    Solution s;
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int x = 0, y = 2, z = 4;
    cout << s.specialNodes(n, edges, x, y, z) << endl; // Output: 3
    return 0;
}