#include<bits/stdc++.h>
using namespace std;
// Problem link : "http://leetcode.com/problems/counting-bits/description/"
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            int x = __builtin_popcount(i);
            ans.push_back(x);
        }
        return ans;
    }
};
int main() {
    Solution obj;
    int n = 5;
    vector<int> res = obj.countBits(n);
    for(int i = 0; i < res.size(); i++) cout << res[i];
    return 0;
}