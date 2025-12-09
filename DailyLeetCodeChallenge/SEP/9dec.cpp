#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
const long long MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<long long, long long> left, right;
        int n = nums.size();
        for(int x : nums) {
            right[x]++;
        }
        for(int j = 0; j < n; j++) {
            int val = nums[j];
            right[val]--;
            int target = val * 2LL;

            long long leftCount = left[target];
            long long rightCount = right[target];

            ans = (ans + leftCount * rightCount) % MOD;
            left[val]++;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {8, 4, 2, 8, 4};
    int result = sol.specialTriplets(nums);
    cout << result;
    return 0;
}