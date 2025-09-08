#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/number-of-enclaves/description/"

class Solution {
public:
vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol =  {0, 1, 0, -1};
void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&  !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
             dfs(nrow, ncol, grid, vis);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis);
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis);
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};
int main() {
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0, 0, 0, 0}};
    Solution s;
    int ans = s.numEnclaves(grid);
    cout << ans;
    return 0;
}