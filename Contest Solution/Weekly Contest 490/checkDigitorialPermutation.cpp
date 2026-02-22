#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int num = n;
        vector<int> fact(10);
        fact[0]=1;
        for(int i = 1;  i < 10; i++) {
            fact[i] = fact[i-1]*i;
        }
        int sum = 0;
        int x = num;
        while(x > 0) {
            int digit = x%10;
            sum+=fact[digit];
            x/=10;
        }
        string a = to_string(num);
        string b = to_string(sum);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};
int main() {
    Solution s;
    int n = 145;
    cout<<s.isDigitorialPermutation(n)<<endl;
    return 0;
}