#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prevIdx = -1;
        for(int currIdx = 0; currIdx < n; currIdx++) {
            if(nums[currIdx] == 1) {
                if(prevIdx != -1 && (currIdx - prevIdx - 1) < k) return false;
                prevIdx = currIdx;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,0,0,1,0,1};
    int k = 2;
    cout << sol.kLengthApart(nums, k);
    return 0;
}