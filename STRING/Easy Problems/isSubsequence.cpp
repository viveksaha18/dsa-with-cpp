#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/is-subsequence/description/"
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(j > s.size()) break;
            if(s[j] == t[i]) {
                j++;
                cnt++;
            }
        }
        return cnt == s.size();
    }
};
int main() {
    string s = "abc";
    string t = "ahbgdc";
    Solution s1;
    cout << s1.isSubsequence(s, t) << endl;
    return 0;
}