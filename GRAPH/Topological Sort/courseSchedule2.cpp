#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem Link : "https://leetcode.com/problems/course-schedule-ii/"
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> inDegree(V, 0);
        for(auto& e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> topo;
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
        if(topo.size() == V) return topo;
        return {};
    }
};
int main() {
    int numCourses= 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    Solution s;
    vector<int> ans = s.findOrder(numCourses, prerequisites);
    for(int it : ans) cout << it << " ";

    return 0;
}