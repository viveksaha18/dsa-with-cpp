#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // currSum -> idx
        unordered_map<int, int> mpp;
        mpp[0]=-1;
        int currSum = 0;
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) currSum-=1;
            else currSum+=1;
            if(mpp.find(currSum) != mpp.end()) {
                int j = mpp[currSum];
                maxLen = max(i-j, maxLen);
            }
            else mpp[currSum]=i;
        }
        return maxLen;
    }
};
int main() {
    Solution s;
    vector<int> nums = {0, 1, 0, 1, 0, 1};
    cout << s.findMaxLength(nums);
    return 0;
}