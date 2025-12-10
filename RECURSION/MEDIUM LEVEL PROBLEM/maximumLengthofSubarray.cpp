#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

int f(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
    if(i >= nums1.size() || j >= nums2.size()) return 0;
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(nums1[i] == nums2[j]) {
        return dp[i][j] = 1 + f(i+1, j+1, nums1, nums2, dp);
    }
    return 0;
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                ans = max(ans, f(i, j, nums1, nums2, dp));
            }
        }
        if(ans == INT_MIN) return 0;
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    cout << s.findLength(nums1, nums2);
    return 0;
}