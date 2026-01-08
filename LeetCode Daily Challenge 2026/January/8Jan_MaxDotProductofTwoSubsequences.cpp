#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int f(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
    if(i == n || j == m) return INT_MIN;
    if(dp[i][j] != -1) return dp[i][j];
    int take = nums1[i]*nums2[j] + max(0, f(i+1, j+1, n, m, nums1, nums2, dp));
    int skip1 = f(i, j+1, n, m, nums1, nums2, dp);
    int skip2 = f(i+1, j, n, m, nums1, nums2, dp);
    return dp[i][j] = max(take, max(skip1, skip2));
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0,0, n, m, nums1, nums2, dp);
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {2,1,-2,5};
    vector<int> nums2 = {3,0,-6};
    cout << s.maxDotProduct(nums1, nums2) << endl;
    return 0;
}