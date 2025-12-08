#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            res.push_back((sum%2) + '0');
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main() {
    Solution sol;
    string a = "1010";
    string b = "1011";
    string result = sol.addBinary(a, b);
    cout << result;
    return 0;
}