#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    int ans = s.maximumProduct(nums);
    cout << ans;
    return 0;
}