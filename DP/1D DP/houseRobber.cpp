#include<bits/stdc++.h>
using namespace std;
/*
Question : 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 
*/

int f(int idx, vector<int>& nums, vector<int>& dp) {
    if(idx == 0) return nums[0];
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + f(idx - 2, nums, dp);
    int notPick = 0 + f(idx - 1, nums, dp);
    return dp[idx] = max(pick, notPick);
}
int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    int n = nums.size();
    vector<int> dp(n, -1);
    cout << f(n - 1, nums, dp) << endl;

    dp.clear();
    dp.resize(n, -1);
    dp[0] = nums[0];
    for(int idx = 1; idx < n; idx++) {
        int pick = nums[idx];
        if(idx > 1) pick = pick + dp[idx - 2];
        int notPick = 0 + dp[idx - 1];
        dp[idx] = max(pick, notPick);
    }
    cout << dp[n - 1] << endl;

    int prev = nums[0], prev2 = 0;
    for(int idx = 1; idx < n; idx++) {
        int pick = nums[idx];
        if(idx > 1) pick = pick + prev2;
        int notPick = 0 + prev;
        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl; // TC : O(n) SC : O(1)
    return 0;
}