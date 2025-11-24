#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for(int b : nums) {
            num = (num * 2 + b) % 5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {0,1,1,1,1,1};
    Solution sol;
    vector<bool> result = sol.prefixesDivBy5(nums);
    for(bool b : result) {
        cout << (b ? "true" : "false") << " ";
    }
    return 0;
}