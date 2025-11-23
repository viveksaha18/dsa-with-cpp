#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        
        vector<int> rem1, rem2;
        
        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) rem1.push_back(x);
            else if (x % 3 == 2) rem2.push_back(x);
        }
        
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());
        
        if (sum % 3 == 0) return sum;
        
        int ans = 0;
        
        if (sum % 3 == 1) {
            int op1 = rem1.size() >= 1 ? sum - rem1[0] : 0;
            int op2 = rem2.size() >= 2 ? sum - rem2[0] - rem2[1] : 0;
            ans = max(op1, op2);
        } else {  
            int op1 = rem2.size() >= 1 ? sum - rem2[0] : 0;
            int op2 = rem1.size() >= 2 ? sum - rem1[0] - rem1[1] : 0;
            ans = max(op1, op2);
        }
        
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3,6,5,1,8};
    cout << sol.maxSumDivThree(nums) << endl; // Output: 18
    return 0;
}