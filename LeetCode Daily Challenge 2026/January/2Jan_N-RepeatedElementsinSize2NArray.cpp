#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mpp;
        for(int x : nums) {
            mpp[x]++;
        }
        int mini = INT_MIN;
        for(auto it : mpp) {
            if(it.second > mini) {
                ans = it.first;
                mini = it.second;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,3,3};
    int result = s.repeatedNTimes(nums);
    cout << result << endl;
    return 0;
}