#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> ans;
vector<int> original;
    Solution(vector<int>& nums) {
        ans = nums;
        original = ans;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        next_permutation(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
    vector<int> nums = {1,2,3};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
    for(auto x:param_1) cout<<x<<" ";
    cout<<endl;
    for(auto x:param_2) cout<<x<<" ";
    return 0;
}