#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/"
class Solution {
public:
bool isNon_Zero(string s) {
    if(s.find('0') != string::npos) return false;
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int> arr;
        for(int i = 1; i < n; i++) {
            string s = to_string(i);
            if(isNon_Zero(s)) {
                int y = n - i;
                string z = to_string(y);
                if(isNon_Zero(z)) {
                    if(arr.size() < 2) {
                        arr.push_back(i);
                        arr.push_back(y);
                        break;
                    }
                }
            }
        }
        return arr;
    }
};
int main() {
    Solution s;
    int n = 11;
    vector<int> ans = s.getNoZeroIntegers(n);
    for(int i = 0; i < 2; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}