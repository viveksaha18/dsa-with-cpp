#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        long long product = 1;
        int left = 0;
        int ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            product = product * nums[r];
            while(product >= k) {
                product = product/nums[left];
                left++;
            }
            ans += r - left + 1;
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << s.numSubarrayProductLessThanK(nums, k);
    return 0;
}