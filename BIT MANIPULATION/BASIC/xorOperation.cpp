#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++) {
            nums[i] = start + 2 * i;
        }
        int bitwiseXOR = 0;
        for(int i = 0; i < nums.size(); i++) {
            bitwiseXOR ^= nums[i];
        }
        return bitwiseXOR;
    }
};
int main() {
    Solution s;
    int n = 5, start = 0;
    int ans = s.xorOperation(n, start);
    cout << ans;
    return 0;
}