#include<bits/stdc++.h>
using namespace std;
class Disjoint {
    vector<int> rank, parent;
    public:
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
int main() {
    Disjoint ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 3);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if(ds.findParent(3) == ds.findParent(7)) cout << "Connected"<< endl;
    else cout << "Not Connected" << endl;
    ds.unionByRank(3, 7);
    if(ds.findParent(3) == ds.findParent(7)) cout << "Connected";
    else cout << "Not Connected";
    return 0;
}