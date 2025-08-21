#include<bits/stdc++.h>
using namespace std;


/*
Question : 
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
double solve(double x, long long b) {
    if(b == 0) return 1;
    if(b < 0) return solve((1/x), -b);
    if(b % 2 == 0) return solve((x*x),b/2);
    return x * solve((x*x), b/2);
}
    double myPow(double x, int n) {
        long long b = n;
        return solve(x, b);
    }
};
int main() {
    double x = 2.00000;
    int n = 10;
    Solution sol;
    double result = sol.myPow(x, n);
    cout << "Result of " << x << "^" << n << " is: " << result << endl;
    // Output: Result of 2.00000^10 is: 1024.00000
    return 0;
}