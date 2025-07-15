#include<bits/stdc++.h>
using namespace std;
/*
Question :
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/


int divideTwoIntegers(int dividend, int divisor){
    bool sign = true;
    if(dividend > 0 && divisor < 0) sign = false;
    if(dividend < 0 && divisor > 0) sign = false;
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    long long ans = 0;
    while(n >= d){
        long long cnt = 0;
        while(n >= d * (1LL << cnt + 1)) cnt++;
        ans += (1LL << cnt);
        n = n - d * (1LL << cnt);
    }
    if(ans >= 1LL << 31) return sign ? INT_MAX : INT_MIN;
    return sign ? (int)ans : (int)-ans;
}
int main(){
    int dividend = 10;
    int divisor = 3;
    int ans = divideTwoIntegers(dividend, divisor);
    cout << ans << endl;
    return 0;
}