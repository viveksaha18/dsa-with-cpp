#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem link : https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // {{r,c}, t}
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int t = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            t = max(t, tm);
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, tm + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return t;
    }
};
int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    int ans = s.orangesRotting(grid);
    cout << ans << endl;
    return 0;
}