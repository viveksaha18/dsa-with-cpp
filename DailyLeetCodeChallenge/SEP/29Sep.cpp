#include<bits/stdc++.h>
using namespace std;
// Problem link : "https://leetcode.com/problems/minimum-score-triangulation-of-polygon/"
class Solution {
public:
int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
    if(j-i+1 < 3) return 0;
    int result = INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    for(int k = i+1; k < j; k++) {
        int wt = solve(values, i, k, dp) + values[i]*values[j]*values[k]+solve(values, k, j, dp);
        result = min(result, wt);
    }
    return dp[i][j] =  result;
}
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n-1, dp);
    }
};
int main() {
    Solution s;
    vector<int> values = {3, 7, 4, 5};
    cout << s.minScoreTriangulation(values);
    return 0;
}