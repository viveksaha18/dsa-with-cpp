#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i > 0 && nums[i-1] < nums[i]) {
            i--;
        }
        return i;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,3,10,0,7,8,9};
    cout << s.minimumPrefixLength(nums) << endl; // Output: 4
    return 0;
}