#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int M = 1e9 + 7;
int f(int sum, int i, int j, vector<vector<int>>& grid, int k, int n, int m, vector<vector<vector<int>>>& dp) {
    if(i >= n || j >= m) return 0;
    if(i == n-1 && j == m-1) {
        return (sum + grid[i][j]) % k == 0;
    }
    if(dp[i][j][sum] != -1) {
        return dp[i][j][sum];
    }
    int down = f((sum+grid[i][j])%k, i+1,j, grid, k, n, m, dp);
    int right = f((sum+grid[i][j])%k, i, j+1, grid, k, n, m, dp);
    return dp[i][j][sum]=(down + right) % M;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return f(0, 0, 0, grid, k, n, m, dp);
    }
};
int main () {
    Solution s;
    vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int k = 3;      
    cout << s.numberOfPaths(grid, k);
    
    return 0;
}