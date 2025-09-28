#include<bits/stdc++.h>
using namespace std;
// Problem link: "https://leetcode.com/problems/largest-perimeter-triangle/description/"
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxPerimeter = 0;
        for(int i = 0; i <= n-3; i++) {
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a+b > c) {
                int peri = a+b+c;
                maxPerimeter = max(peri, maxPerimeter);
            }
        }
        return maxPerimeter;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,1,2}; 
    cout << s.largestPerimeter(nums) << endl;
    return 0;
}