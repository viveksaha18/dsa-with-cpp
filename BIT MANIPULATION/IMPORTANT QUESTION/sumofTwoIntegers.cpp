#include<bits/stdc++.h>
using namespace std;
// Problem link : "https://leetcode.com/problems/sum-of-two-integers/submissions/1813259669/"

class Solution {
public:
    int getSum(int a, int b) {
        unsigned carry = a & b;
        int sum = a ^ b;
        int actualCarry = carry << 1;
        while(carry != 0) {
            carry = sum & actualCarry;
            sum = sum ^ actualCarry;
            actualCarry = carry << 1;
        }
        return sum;
    }
};
int main() {
    Solution s;
    int a = 2, b = 5;
    int ans = s.getSum(a, b);
    cout << ans;
    return 0;
}