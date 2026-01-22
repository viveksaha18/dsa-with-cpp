#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(2^n * n)
// Space Complexity : O(n)
class Solution {
public:
string arr;
unordered_map<string, int> mpp;
void allCombinations(int idx, int n) {
    if(idx == n) {
        mpp[arr] = -1;
        return ;
    }
    arr.push_back('0');
    allCombinations(idx+1, n);
    arr.pop_back();
    arr.push_back('1');
    allCombinations(idx+1, n);
    arr.pop_back();
}
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        int n = nums.size();
        allCombinations(0, n);
        for(auto it : nums) {
            mpp[it] = 1;
        }

        for(auto it : mpp) {
            if(it.second == -1) {
                return it.first;
            }
        }

        return ans;
    }
};
int main() {
    Solution s;
    vector<string> nums = {"01","10"};
    string ans = s.findDifferentBinaryString(nums);
    cout << ans << endl;
    return 0;
}