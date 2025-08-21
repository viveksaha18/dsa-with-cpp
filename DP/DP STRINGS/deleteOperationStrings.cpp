#include<bits/stdc++.h>
using namespace std;

/*
Question: 
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/
int f(int idx1, int idx2, string& text1, string& text2, vector<vector<int>>& dp) {
    if(idx1 < 0 || idx2 < 0) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if(text1[idx1] == text2[idx2]) return dp[idx1][idx2] = 1 + f(idx1 - 1, idx2 - 1, text1, text2, dp);
    return dp[idx1][idx2] = max(f(idx1 - 1, idx2, text1, text2, dp), f(idx1, idx2 - 1, text1, text2, dp));
}
int lcs(string text1, string text2) {
        int idx1 = text1.size();
        int idx2 = text2.size();
        vector<vector<int>> dp(idx1, vector<int> (idx2, -1));
        return f(idx1 - 1, idx2 - 1, text1, text2, dp);
}
int main() {
    string word1 = "sea";
    string word2 = "eat";
    cout << word1.size() + word2.size() - 2 * lcs(word1, word2);
    return 0;
}