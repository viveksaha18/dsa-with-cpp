#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(unordered_map<int, int>& mpp, int ele) {
        int freq = mpp[ele];
        for(auto it : mpp) {
            if(it.first == ele) continue;
            if(freq == it.second) {
                return false;
            }
        }
        return true;
    }
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            if(check(mpp, ele)) {
                ans = ele;
                break;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 3, 4};
    cout << s.firstUniqueFreq(nums) << endl;
    return 0;
}