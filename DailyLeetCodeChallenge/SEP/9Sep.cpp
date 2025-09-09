#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/number-of-people-aware-of-a-secret/"
class Solution {
public:
int M = 1e9+7;

int solve(int day, int forget, int delay, vector<int>& dp) {
    if(day == 1) return 1;
    if(dp[day] != -1) return dp[day];
    int result = 0;
    for(int d = day - forget + 1; d <= day - delay; d++) {
        if(d > 0) result = (result + solve(d, forget, delay, dp)) % M;
    }
    return dp[day] = result;
}
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        vector<int> dp(n+1, -1);
        for(int day = n - forget + 1; day <= n; day++) {
            if(day > 0)
                total = (total + solve(day, forget, delay, dp)) % M;
        }
        return total;
    }
};
int main() {
    int n = 6, delay = 2, forget = 4;
    Solution s;
    int ans = s.peopleAwareOfSecret(n, delay, forget);
    cout << ans;
    return 0;
}