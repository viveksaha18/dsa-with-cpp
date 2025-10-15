#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/defanging-an-ip-address/description/"
// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c : address) {
            if(c != '.') {
                res.push_back(c);
            }
            else res += "[.]";
        }
        return res;
    }
};
int main() {
    string address = "1.1.1.1";
    Solution s;
    cout << s.defangIPaddr(address) << endl;
    return 0;
}