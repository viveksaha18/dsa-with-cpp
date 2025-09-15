#include<bits/stdc++.h>
using namespace std;
int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 3}};
    vector<int> inDegree(V, 0);
    vector<vector<int>> adj(V);
    queue<int> q;
    vector<int> topo;
    for(auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }
    //inDegree 
   
    for(int i = 0; i < V; i++) {
        for(auto it : adj[i]) {
            inDegree[it]++;
        }
    }
    
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]) {
            inDegree[it]--;
            if(inDegree[it] == 0) {
                q.push(it);
            }
        }
    }
    if(topo.size() == V) cout << "False";
    else cout << "True";
    return 0;
}