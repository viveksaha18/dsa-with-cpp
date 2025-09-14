#include<bits/stdc++.h>
using namespace std;
// This can be solve using the cylce detection logic 
// Leetcode Problem Link : "https://leetcode.com/problems/course-schedule/"
class Solution {
public:
bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
    vis[node] = 1;
    pathVis[node] = 1;
    
    
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(dfs(it, vis, pathVis, adj) == true) return true;
        }
        else if(pathVis[it]) return true;
    }
    
    
    pathVis[node] = 0;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i = 0;  i < numCourses; i++) {
            if(dfs(i, vis, pathVis, adj)) return false;
        }
        return true;
    }
};
int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    Solution s;
    bool ans = s.canFinish(numCourses, prerequisites);
    if(ans) cout << "True";
    cout << "False";
    return 0;
}