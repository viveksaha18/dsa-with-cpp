#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        vector<int> ans;
        for(auto it : mpp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = s.findDuplicates(nums);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}