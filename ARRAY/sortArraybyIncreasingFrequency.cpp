#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) 
        return b.first < a.first;
    return a.second < b.second;
}
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int x : nums) {
            mpp[x]++;
        }
        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(auto it : v) {
            int ele = it.first;
            int times = it.second;
            for(int i = 0; i < times; i++) 
                ans.push_back(ele);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,2,2,2,3};
    vector<int> result = s.frequencySort(nums);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}