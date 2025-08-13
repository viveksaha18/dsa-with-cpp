#include<bits/stdc++.h>
using namespace std;
/*
Question :
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
The cost of a jump is the absolute difference in height between the two stairs.
Determine the minimum total cost required for the frog to reach the top.

Example:

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20


Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30
*/

int f(int idx, vector<int>& heights, vector<int>& dp) {
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int left = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
    int right = INT_MAX;
    if(idx > 1) right = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
    return dp[idx] = min(left, right);
}
int main() {
    vector<int> heights = {20, 30, 40, 20};
    int n = heights.size();
    vector<int> dp(n, -1);
    cout << f(n - 1, heights, dp) << endl;

    dp.clear();
    dp.resize(n, -1);
    dp[0] = 0;
    for(int idx = 1; idx < n; idx++) {
        int left = dp[idx - 1] + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1) right = dp[idx - 2] + abs(heights[idx] - heights[idx - 2]);
        dp[idx] = min(left, right);
    }
    cout << dp[n - 1] << endl;

    int prev = 0, prev2 = 0;
    for(int idx = 1; idx < n; idx++) {
        int left = prev + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1) right = prev2 + abs(heights[idx] - heights[idx - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
    return 0;
}