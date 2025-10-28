#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1814070510/"
class Solution {
public:
int binarySearch(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = l+(r-l)/2;
        if(nums[mid] == target) return mid;
        if(nums[l] <= nums[mid]) {
            // check in the left sorted half
            if(nums[l] <= target && target <= nums[mid]) {
                r = mid-1;
            }
            else l = mid + 1;
        }
        else {
            // check in the sorted right half
            if(nums[mid] <= target && target <= nums[r]) {
                l = mid+1;
            }
            else r = mid-1;
        }
    }

    return -1;
}
    int search(vector<int>& nums, int target) {
        int ans = binarySearch(nums, target);
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2,3};
    int target = 0;
    int ans = s.search(nums, target);
    cout << ans;
    return 0;
}