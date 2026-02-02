#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    int cnt = 1;
    int n = grid.size();
    int m = grid[0].size();
    // {row, col}
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1) {
                cnt++;
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    return cnt;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    int ans = bfs(i, j, grid, vis);
                    maxi = max(ans, maxi);
                }
            }
        }
        return maxi;
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    int ans = s.maxAreaOfIsland(grid);
    cout << ans << endl;
    return 0;
}