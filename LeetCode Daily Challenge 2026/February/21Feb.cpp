#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int countSetBits(int n) {
    int count = __builtin_popcount(n);
    return count;
}
bool isPrime(int n) {
    int factors = 0;
    for(int i = 1; i <= n; i++) {
        if(n%i == 0) factors++;
    }
    if(factors == 2) return true;
    return false;
}
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++) {
            int setBits = countSetBits(i);
            if(isPrime(setBits)) cnt++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    int left = 6, right = 10;
    cout << s.countPrimeSetBits(left, right) << endl;
    return 0;
}