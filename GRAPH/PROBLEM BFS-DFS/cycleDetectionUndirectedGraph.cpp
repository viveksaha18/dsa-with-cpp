#include<bits/stdc++.h>
using namespace std;

// GFG Problem Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
     bool detect(int src, vector<int> &vis, vector<vector<int>>&adjls)
    {
        vis[src]=1;
        
        queue<pair<int,int>>q;
        
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto itr:adjls[node])
            {
                if(vis[itr]==0)
                {
                    vis[itr]=1;
                    q.push({itr,node});
                }
                else if(parent!=itr)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjls(V);
        
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            adjls[edges[i][0]].push_back(edges[i][1]);
            adjls[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0) 
            {
                if(detect(i,vis,adjls)==true) return true;
            }
        }
        return false;
    }
};
int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    Solution s;
    bool ans = s.isCycle(V, edges);
    cout << ans << endl;
    return 0;
}