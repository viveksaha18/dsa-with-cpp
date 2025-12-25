#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
unordered_map<int, int> mpp;
int r = 0;
void f(int idx, vector<int>& nums, int k) {
    if(idx >= nums.size()) {
        r++;
        return;
    }
    f(idx+1, nums, k);
    if(!mpp[nums[idx]-k] && !mpp[nums[idx]+k]) {
        mpp[nums[idx]]++;
        f(idx+1, nums, k);
        mpp[nums[idx]]--;
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
        f(0, nums, k);
        return r-1;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,4,6};
    int k = 2;
    cout << sol.beautifulSubsets(nums, k) << endl;
    return 0;
}