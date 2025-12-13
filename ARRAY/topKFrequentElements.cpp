#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static bool cmp(pair<int, int>&a, pair<int, int>& b) {
    return a.second > b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;
        int i = 0;
        for(auto it :vec) {
            if(i == k) break;
            ans.push_back(it.first);
            i++;
        }
        return ans;
        
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = s.topKFrequent(nums, k);
    
    return 0;
}