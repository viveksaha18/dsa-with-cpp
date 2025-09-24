#include<bits/stdc++.h>
using namespace std;
// Problem link : "https://leetcode.com/problems/count-elements-with-maximum-frequency/"

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums) {
            mpp[num]++;
        }
        int maxFreq = 0;
        for(auto& it : mpp) {
            int freq = it.second;
            maxFreq = max(maxFreq, freq);
        }
        int maxCnt = 0;
        for(auto& it : mpp) {
            int freq = it.second;
            if(freq == maxFreq) {
                maxCnt++;
            }
        }
        return maxFreq * maxCnt;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,2,3,3,3};   
    cout<<s.maxFrequencyElements(nums);
    return 0;
}