#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < n; i+=2) {
            sum += min(nums[i], nums[i+1]);
        }
        return sum;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,4,3,2};
    cout << "The maximum sum of min pairs is: " << s.arrayPairSum(nums) << endl;
    return 0;
}