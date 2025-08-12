#include<bits/stdc++.h>
using namespace std;
/*
Question : 
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
*/
int recursion_climbStars(int n) {
    if(n <= 2) return n;

    return recursion_climbStars(n - 1) + recursion_climbStars(n - 2);
}

int recursion_climbStars(int n, vector<int>& dp) {
    if(n <= 2) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursion_climbStars(n - 1, dp) + recursion_climbStars(n - 2, dp);
}
int main() {
    int n = 3;
    cout << recursion_climbStars(n) << endl;

    // memoization - top down approach 
    vector<int> dp(n + 1, -1);
    cout << recursion_climbStars(n, dp) << endl;

    // Tabulation - bottom up approach
    vector<int> dpTabulation(n + 1, 0);
    dpTabulation[0] = 0, dpTabulation[1] = 1, dpTabulation[2] = 2;
    for(int i = 3; i <= n; i++) {
        dpTabulation[i] = dpTabulation[i - 1] + dpTabulation[i - 2];
    }
    cout << dpTabulation[n] << endl;

    // Space Optimization
    
    int prev = 2, prev2 = 1;
    for(int i = 3; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl; // it makes a solution of constant space complexity O(1)
    return 0;
}