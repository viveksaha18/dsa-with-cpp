#include<bits/stdc++.h>
using namespace std;
/*
Question : 
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/


int f(int i, int j, vector<vector<int>>& dp) {
    if(i == 0 && j == 0) return 1;
    if(i <  0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int main() {
    int m = 3, n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << f(m - 1, n - 1, dp) << endl;

    // Tabulation
    dp.clear();
    dp.resize(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) dp[0][0] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    cout << dp[m - 1][n - 1] << endl;

    // Space Optimization 
    vector<int> prev(m, 0);
    for(int i = 0; i < m; i++) {
        vector<int> curr(m, 0);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) curr[0] = 1;
            else {
                int up = 0;
                int left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = curr[j - 1];
                curr[j]= up + left;
            }
        }
        prev = curr;
    }
    cout << prev[n - 1];
    return 0;
}