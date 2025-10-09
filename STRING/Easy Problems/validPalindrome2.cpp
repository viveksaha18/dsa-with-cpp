#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/valid-palindrome-ii/description/"
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
bool isPalindrome(string s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end) {
            if(s[start] == s[end]) {
                start++, end--;
            }
            else {
                return isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1);
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    string str = "abca";
    cout << s.validPalindrome(str) << endl;
    return 0;
}