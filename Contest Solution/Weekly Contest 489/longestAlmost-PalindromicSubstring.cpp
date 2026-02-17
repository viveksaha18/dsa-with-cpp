#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i, int j, string& s, vector<vector<int>>& dp) {
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i]==s[j]) {
        return dp[i][j] = solve(i+1, j-1, s, dp);
    }
    int left = solve(i+1, j, s, dp);
    int right = solve(i, j-1, s, dp);
    int ans =  1+min(left, right);
    if(ans > 1) {
        ans = 2;
    }
    return dp[i][j] = ans;
}
    int almostPalindromic(string s) {
        int n = s.size();
        int maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(solve(i, j, s, dp) <= 1 && j - i + 1 >= 2) {
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};
int main() {
    Solution s;
    string input = "abccba";
    cout << s.almostPalindromic(input) << endl;
    return 0;
}