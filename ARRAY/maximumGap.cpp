#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            ans = max(ans, nums[i] - nums[i-1]);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {3,6,9,1};
    int ans = s.maximumGap(nums);
    cout << ans << endl;
    return 0;
}