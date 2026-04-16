#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int f(int n, vector<int>& dp) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    for(int i = 1; i*i <= n; i++) {
        ans = min(ans, 1+f(n-i*i, dp));
    }
    return dp[n] = ans;
}
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};
int main() {
    Solution s;
    int n = 12;
    cout << s.numSquares(n) << endl;
    return 0;
}