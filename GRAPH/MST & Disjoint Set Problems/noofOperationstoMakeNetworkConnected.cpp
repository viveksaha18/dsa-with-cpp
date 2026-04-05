#include<bits/stdc++.h>
using namespace std;
class Disjoint {
    public:
    vector<int> rank, parent;
    Disjoint(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) parent[i]=i;
    }
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int up_u = findParent(u);
        int up_v = findParent(v);
        if(up_u == up_v) return;
        if(rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        }
        else if(rank[up_v] < rank[up_u]) {
            parent[up_v] = up_u;
        }
        else {
            parent[up_u]=up_v;
            rank[up_u]=rank[up_u]+1;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int cntExtras = 0;
        int nC=0;
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)) cntExtras++;
            else ds.unionByRank(u, v);
        }
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) nC++;
        }
        int ans = nC-1;
        if(cntExtras >= ans) {
            return ans;
        }
        return -1;
    }
};
int main() {
    Solution s;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout << s.makeConnected(n, connections);
    return 0;
}