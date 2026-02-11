#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for(long long i = 2; i < n; i++) {
            if(isPrime[i]) {
                for(long long j = i*i; j < n; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(isPrime[i]) cnt++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    int n = 10;
    cout << s.countPrimes(n) << endl;
    return 0;
}