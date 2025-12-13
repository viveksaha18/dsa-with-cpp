#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        int l = (n-1)/2, r = n-1;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                ans[i] = nums[l];
                l--;
            }
            else {
                ans[i] = nums[r];
                r--;
            }
        }
        nums = ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,5,1,1,6,4};
    s.wiggleSort(nums);
    return 0;
}