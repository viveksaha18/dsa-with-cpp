#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long minMaxValue = nums[n-1];
        long long res = 0;
        for(int i = n-2; i >= 0; i--) {
            long long parts = ceil(nums[i]/(double)minMaxValue);
            res+=(parts-1);
            minMaxValue = nums[i]/parts;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {3,9,3};
    long long ans = s.minimumReplacement(nums);
    cout << ans;
    return 0;
}