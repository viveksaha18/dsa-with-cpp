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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        Disjoint ds(maxRow + maxCol +1);
        unordered_map<int, int> stoneNodes;
        for(auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1]+maxRow+1;
            ds.unionByRank(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it : stoneNodes) {
            if(ds.findParent(it.first) == it.first) cnt++;
        }
        return n-cnt;
    }
};
int main() {
    Solution s;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << s.removeStones(stones);
    return 0;
}