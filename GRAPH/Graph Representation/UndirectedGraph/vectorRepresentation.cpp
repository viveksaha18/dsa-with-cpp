#include<bits/stdc++.h>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    // undirected graph
    for(int i = 0 ; i < m ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto it : adj) {
        cout << it[0] << " -> ";
        for(auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    // directed graph 
    for(int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v;
        // u -----> v
        adj[u].push_back(v);
    }
    return 0;
}