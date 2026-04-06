#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                if(mpp.find(s) == mpp.end()) mpp[s]=i;
                else {
                    ds.unionByRank(mpp[s], i);
                }
            }
        }
        vector<vector<string>> v(n);
        for(auto it : mpp) {
            string mail = it.first;
            int node = it.second;
            int ul_p = ds.findParent(node);
            v[ul_p].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(v[i].size() == 0) continue;
            sort(v[i].begin(), v[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : v[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john00@mail.com"},{"John","johnnybravo@mail.com"},{"John","johnsmith@mail.com","john_newyork@mail.com"},{"Mary","mary@mail.com"}};
    vector<vector<string>> result = s.accountsMerge(accounts);
    for(auto it : result) {
        for(auto email : it) {
            cout << email << " ";
        }
        cout << endl;
    }
    return 0;
}