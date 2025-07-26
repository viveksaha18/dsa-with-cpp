#include<bits/stdc++.h>
using namespace std;
/*
Question:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/


// Water will Trapped at index where   min(leftMax, rightMax) - height[i] 



// Brute Force Approach : For Every Index, I have to find the maximum height on left and right side of that index 
int trappingRainWater_Brute(vector<int>& height) {
    int n = height.size();
    int ans = 0;
    // for leftMax
    for(int i = 1; i < n; i++){
        int leftMax = 0, rightMax = 0;
        for(int j = i - 1; j >= 0; j--) {
            leftMax = max(leftMax, height[j]);
        }
        // for rightMax
        for(int j = i + 1; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }
        // computing the formula
        int waterTrap = min(leftMax, rightMax) - height[i];
        if(waterTrap > 0) {
            ans += waterTrap;
        }
    }
    return ans;
}


// Optimal Solution : Using next greater and previous greater element

int trappingRainWater_Optimal(vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n,0);
    vector<int> rightMax(n,0);
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    // rightMax
    for(int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }
    // leftMax
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(height[i], leftMax[i - 1]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += min(leftMax[i], rightMax[i]) - height[i];
    }
    return cnt;
}
int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int bruteAns = trappingRainWater_Brute(height);
    cout << bruteAns << endl;
    int optimalAns = trappingRainWater_Optimal(height);
    cout << optimalAns << endl;
    return 0;
}