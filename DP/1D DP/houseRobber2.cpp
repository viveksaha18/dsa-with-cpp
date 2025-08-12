#include<bits/stdc++.h>
using namespace std;
/* 
Question : 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
*/

// Extended version of house robber 

class Solution {
public:
int ans(vector<int> nums) {
    int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for(int i = 1; i < n; i++) {
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int non_pick = 0 + prev;
            int curri = max(pick, non_pick);
            prev2 = prev;
            prev = curri;
        }
        return prev;
}
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp(nums.begin(), nums.end() - 1);
        vector<int> temp1(nums.begin() + 1, nums.end());
        int val1 = ans(temp);
        int val2 = ans(temp1);
        return max(val1, val2);
    }
};
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 1};
    cout << obj.rob(nums) << endl;
    return 0;
}