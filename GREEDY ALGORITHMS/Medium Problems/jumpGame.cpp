#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/jump-game/description/"
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.canJump(nums) << endl;
    return 0;
}