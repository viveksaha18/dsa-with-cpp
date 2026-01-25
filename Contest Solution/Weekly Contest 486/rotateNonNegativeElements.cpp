#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> ans;
        for(auto x : nums) {
            if(x >= 0) {
                ans.push_back(x);
            }
        }
        int n = ans.size();
        if(n == 0) return nums;
        k%=n;
        rotate(ans.begin(), ans.begin()+k, ans.end());
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                nums[i] = ans[j];
                j++;
            }
        }
        return nums;
    }
};
int main() {
    Solution s;
    vector<int> nums = { -1, 2, 3, -4, 5, 6 };
    int k = 2;
    vector<int> result = s.rotateElements(nums, k);
    for(int x : result) {
        cout << x << " ";
    }
    return 0;
}