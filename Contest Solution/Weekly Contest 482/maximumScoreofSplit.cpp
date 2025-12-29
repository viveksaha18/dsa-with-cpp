#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i+1]);
        }
        long long prefixSum = 0;
        long long score = INT_MIN;
        for(int i = 0; i < n-1; i++) {
            prefixSum += nums[i];
            long long currScore = prefixSum - suffixMin[i+1];
            score = max(currScore, score);
        }
        return score;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,5,1,3,4,7};
    cout << s.maximumScore(nums) << endl;
    return 0;
}