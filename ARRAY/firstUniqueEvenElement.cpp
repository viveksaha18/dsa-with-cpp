#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(auto x : nums) {
            mpp[x]++;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0 && mpp[nums[i]] == 1) return nums[i];
        }
        return -1;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 2, 3, 5};
    cout << s.firstUniqueEven(nums) << endl;
    return 0;
}