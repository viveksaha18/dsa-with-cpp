#include<bits/stdc++.h>
using namespace std;

// Aprroach 1: Using Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;
        vector<int>ans;
        for(auto it : mpp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// Approach 2: Using Bit Manipulation Using XOR
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // take out of xor of nums
        int num = 0;
        for(auto x : nums) {
            num ^= x;
        }
        // findout the rightmostBit of nums
        unsigned int  rightmostBit = num & -(unsigned int)num;
        int a = 0, b = 0;
        for(int num : nums) {
            if(num&rightmostBit) a^=num;
            else b^=num;
        }
        return {a, b};
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = s.singleNumber(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    Solution1 s1;
    vector<int> ans1 = s1.singleNumber(nums);
    for(int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " ";
    }
    return 0;
}