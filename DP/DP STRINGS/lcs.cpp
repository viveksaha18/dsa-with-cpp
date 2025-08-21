#include<bits/stdc++.h>
using namespace std;

/*
Question :
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

int f(int idx1, int idx2, string& text1, string & text2, vector<vector<int>>& dp) {
    if(idx1 < 0 || idx2 < 0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(text1[idx1] == text2[idx2]) return dp[idx1][idx2] =  1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);
    return dp[idx1][idx2] = max(f(idx1 - 1, idx2, text1, text2, dp), f(idx1, idx2 - 1, text1, text2, dp));
}
int main() {
    string text1 = "abaaa";
    string text2 = "baabaca";
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout << f(n1 - 1, n2 - 1, text1, text2, dp) << endl;
    

    vector<vector<int>> dp2(n1 + 1, vector<int>(n2 + 1, 0));
    //for(int i = 0; i <= n1; i++) dp2[i][0] = 0;
    //for(int j = 0; j <= n2; j++) dp2[0][j] = 0;
    
    for(int idx1 = 1; idx1 <= n1; idx1++) {
        for(int idx2 = 1; idx2 <= n2; idx2++) {
            if(text1[idx1 - 1] == text2[idx2 - 1]) dp2[idx1][idx2] =  1 + dp2[idx1 - 1][idx2 - 1];
            else dp2[idx1][idx2] = max(dp2[idx1 - 1][idx2], dp2[idx1][idx2 - 1]);
        }
    }
    cout << dp2[n1][n2] << endl;


    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    /*// Space Optimized Approach
    vector<int> prev(n2 + 1, 0);
    for(int idx1 = 1; idx1 <= n1; idx1++) {
        vector<int> curr(n2 + 1, 0);
        for(int idx2 = 1; idx2 <= n2; idx2++) {
            if(text1[idx1 - 1] == text2[idx2 - 1]) curr[idx2] =  1 + prev[idx2 - 1];
            else curr[idx2] = max(prev[idx2], curr[idx2 - 1]);
        }
        prev = curr;
    }
    cout << prev[n2];*/
    return 0;
}