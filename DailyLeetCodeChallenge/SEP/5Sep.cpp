#include<bits/stdc++.h>
using namespace std;
// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 1; k <= 60; k++) {
            long long target = 1LL*num1 - 1LL*k*num2;
            if(target < 0) continue;
            
            int powerofTwo = __builtin_popcountll(target);
            if(powerofTwo > k) continue;
            if(k <= target) return k;
        }
        return -1;
    }
};
int main() {
    Solution s;
    cout << s.makeTheIntegerZero(3, -2) << endl;
    return 0;
}