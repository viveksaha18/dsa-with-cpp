#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int lowerBound(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, h = n-1;
    while(l <= h) {
        int mid = l+(h-l)/2;
        if(nums[mid] >= k) {
            n=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return n;
}
int upperBound(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, h = n-1;
    while(l <= h) {
        int mid = l+(h-l)/2;
        if(nums[mid] > k) {
            n=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return n;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int lb = lowerBound(nums, target);
        if(lb == nums.size() || nums[lb] != target) return {-1, -1};
        int ub = upperBound(nums, target);
        int lastOccurence = ub-1;
        return {lb, lastOccurence};
    }
};


int main() {
    Solution s;
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = s.searchRange(arr, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}