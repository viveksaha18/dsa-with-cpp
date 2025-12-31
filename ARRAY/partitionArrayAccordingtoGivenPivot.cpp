#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < p) ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == p) ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > p) ans.push_back(nums[i]);
        }
        return ans;
    }
};
int main()  {
    Solution s;
    vector<int>nums = {9,12,5,10,14,3,10};
    int p = 10;
    vector<int>result = s.pivotArray(nums, p);
    for(int val : result) {
        cout << val << " ";
    }
    return 0;
}