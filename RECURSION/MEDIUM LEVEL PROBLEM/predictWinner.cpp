#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(int i, int j, vector<int>& nums) {
    if(i == j) return nums[i];
    int takeFromLeft = nums[i] - solve(i+1, j, nums);
    int takeFromRight = nums[j] - solve(i, j-1, nums);
    return max(takeFromLeft, takeFromRight);
}
    bool predictTheWinner(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int diff = solve(i, j, nums);
        return diff >= 0;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 5, 2};
    cout << s.predictTheWinner(nums) << endl;
    return 0;
}