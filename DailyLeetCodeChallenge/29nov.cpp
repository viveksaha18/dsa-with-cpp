#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(int it : nums) {
            sum += it;
        }
        return sum % k;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int k = 3;
    cout << sol.minOperations(nums, k) << endl;
    return 0;
}