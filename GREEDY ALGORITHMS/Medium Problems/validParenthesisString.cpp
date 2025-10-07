#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/valid-parenthesis-string/"
class Solution {
public:

bool f(string s, int idx, int cnt, vector<vector<int>>& dp) {
    if(cnt == -1) return false;
    if(idx == s.size()) return cnt == 0;
    if(dp[idx][cnt] != -1) return dp[idx][cnt];
    bool res = false;
    if(s[idx] == '(') {
         res = f(s, idx + 1, cnt + 1, dp);
    }
    else if(s[idx] == ')') {
         res= f(s, idx + 1, cnt - 1, dp);
    }

    else  res =  f(s, idx + 1, cnt + 1, dp) || f(s, idx + 1, cnt, dp) || f(s, idx + 1, cnt - 1, dp);
    return dp[idx][cnt] = res;
}
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(s, 0, 0, dp);
    }
};
int main() {
    Solution s;
    string str = "(*)";
    bool ans = s.checkValidString(str);
    if(ans) cout << "True";
    else cout << "False";
    return 0;
}