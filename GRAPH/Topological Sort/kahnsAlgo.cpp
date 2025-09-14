#include<bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgo(vector<vector<int>>& edges, int V) {
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
    return topo;
}
int main() {
    int n = 6;
    vector<vector<int>> edges = {{5, 0}, {5, 2}, {2, 3}, {4, 0}, {4, 1}, {3, 1}};
    vector<int> ans = kahnsAlgo(edges, n);
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}