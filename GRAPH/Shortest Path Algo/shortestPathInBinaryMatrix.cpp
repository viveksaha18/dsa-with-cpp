#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        dis[0][0]=1;
        q.push({1, {0, 0}});
        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int d=p.first;
            int row=p.second.first;
            int col=p.second.second;
            for(int i = 0; i < 8; i++) {
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow < n && ncol < n && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 0 && dis[nrow][ncol] > d+1) {
                    dis[nrow][ncol]=d+1;
                    if(nrow == n-1 && ncol == n-1) {
                        return d+1;
                    }
                    q.push({d+1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid={
        {0,1},
        {1,0}
    };
    int ans = s.shortestPathBinaryMatrix(grid);
    cout << ans;
    return 0;
}