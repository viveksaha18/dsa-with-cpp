#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0;
        long long maxSum = INT_MIN;
        unordered_map<int, int> mpp;
        int r = 0, l = 0, n = nums.size();
        while(r < n && l < n) {
            
            while(mpp.count(nums[r]) && mpp[nums[r]] >= l) {
                currSum-=nums[l];
                l++;
            }
            currSum += nums[r];
            mpp[nums[r]]=r;
            while(r-l+1 > k) {
                currSum-=nums[l];
                l++;
            }

            if(r-l+1 == k) {
                maxSum = max(currSum, maxSum);
            }
            r++;
        }
        if(maxSum == INT_MIN) return 0;
        return maxSum;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    cout<<s.maximumSubarraySum(nums, k);
    return 0;
}