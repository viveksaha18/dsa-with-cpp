#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        if(need1 == 0 && need2 == 0) return 0;
        long long ans = 0;
        if(costBoth < cost1+cost2) {
            int mini = min(need1, need2);
            ans += costBoth*mini;
            if(need1 > need2) {
                long long extra = need1 - need2;
                if(costBoth < cost1) {
                    ans += costBoth*extra;
                }
                else {
                    ans += extra*cost1;
                }
            }
            else {
                long long extra = need2 - need1;
                if(costBoth < cost2) {
                    ans += costBoth*extra;
                }
                else {
                    ans += extra*cost2;
                }
            }
        }
        else {
            ans += cost1*need1;
            ans += cost2*need2;
        }
        return ans;
    }
};
int main() {
    Solution s;
    cout << s.minimumCost(1, 3, 4, 2, 1) << endl;
    return 0;
}