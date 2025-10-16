#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/lexicographical-numbers/"
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
public:
vector<int> res;
void solve(int currNum, int n) {
    if(currNum > n) return;
    res.push_back(currNum);
    for(int append = 0; append <= 9; append++) {
        int newNum = (currNum * 10) + append;
        if(newNum > n) return;
        solve(newNum, n);
    }
}
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++) {
            solve(i, n);
        }
        return res;
    }
};
int main() {
    int n = 13;
    Solution s;
    vector<int> res = s.lexicalOrder(n);
    for(auto it : res) {
        cout << it << " ";
    }
    return 0;
}