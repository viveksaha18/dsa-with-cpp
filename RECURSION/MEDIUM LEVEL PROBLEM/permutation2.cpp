#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
set<vector<int>> st;
void f(int i, vector<int>& nums) {
    if(i == nums.size()) {
        st.insert(nums);
        return;
    }
    for(int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        f(i+1, nums);
        swap(nums[i], nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        f(0, nums);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for(auto v : ans) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}