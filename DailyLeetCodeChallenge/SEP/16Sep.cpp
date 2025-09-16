#include <bits/stdc++.h>
using namespace std;

long long custom_gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long custom_lcm(long long a, long long b) {
    return (a / custom_gcd(a, b)) * b;
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for (int num : nums) {
            while (!result.empty()) {
                int prev = result.back();
                int GCD = custom_gcd(prev, num);
                if (GCD == 1) break;
                num = custom_lcm(prev, num);
                result.pop_back();
            }
            result.push_back(num);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {6, 4, 3, 2, 7, 6, 2};
    Solution s;
    vector<int> ans = s.replaceNonCoprimes(nums);

    for (int it : ans) cout << it << " ";
    return 0;
}
