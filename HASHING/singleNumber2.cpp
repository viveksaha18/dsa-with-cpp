#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem Link : "https://leetcode.com/problems/single-number-ii/"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;
        for(auto it : mpp) {
            if(it.second == 1) {
                return it.first;
            }
        }
        return 0;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 2};
    int ans = s.singleNumber(nums);
    cout << ans;
    return 0;
}