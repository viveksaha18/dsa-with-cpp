#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int n;
int m;
int dp[501][501][3];
int f(int r, int c, int neu, vector<vector<int>>& grid) {  
    if(r == n-1 && c == m-1) {
        if(grid[r][c] < 0 && neu > 0) {
            return 0;
        }
        return grid[r][c];
    }
    if(dp[r][c][neu] != INT_MIN) return dp[r][c][neu];
    if(r >= n || c >= m) return INT_MIN;
    int take = grid[r][c] + max(f(r+1, c, neu, grid), f(r, c+1, neu, grid));
    int notTake = INT_MIN;
    if(grid[r][c] < 0 && neu > 0) {
        notTake = max(f(r+1, c, neu-1, grid), f(r, c+1, neu-1, grid));
    }
    return dp[r][c][neu]=max(take, notTake);
}
    int maximumAmount(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        return f(0, 0, 2, grid);
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid = {{1,-3,2},{1,-5,-1},{3,-2,1}};
    cout << s.maximumAmount(grid) << endl;
    return 0;
}