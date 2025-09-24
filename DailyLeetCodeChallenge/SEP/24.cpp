#include<bits/stdc++.h>
using namespace std;
// Problem link : "https://leetcode.com/problems/fraction-to-recurring-decimal/description/"

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string result;
        if(n == 0) {
            return "0";
        }
        if((long long) n * (long long)d < 0) {
            result += "-";
        }
        long long numerator = labs(n);
        long long denominator = labs(d);
        result += to_string(numerator/denominator);
        long long remainder = numerator % denominator;
        if(remainder == 0) return result;
        unordered_map<int, int> mpp;
        result += '.';
        while(remainder != 0) {
            if(mpp.find(remainder) != mpp.end()) {
                result.insert(mpp[remainder], "(");
                result += ")";
                break;
            }
            mpp[remainder] = result.length();
            remainder = remainder * 10;
            result += to_string(remainder / denominator);
            remainder = remainder % denominator;
        }
        return result;
    }
};
int main() {
    Solution s;
    cout<<s.fractionToDecimal(4,333);
    return 0;
}