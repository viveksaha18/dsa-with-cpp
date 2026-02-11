#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        vector<bool> isPrime(n, true);
        isPrime[0]=isPrime[1] = false;
        for(long long i = 2; i < n; i++) {
            if(isPrime[i]) {
                for(long long j = i*i; j < n; j += i) {
                    isPrime[j]=false;
                }
            }
        }
        for(int i = 2; i < n ; i++) {
            if(isPrime[i]) {
                int key = n-i;
                if(isPrime[key]) {
                    ans.push_back({i, key});
                }
                isPrime[key]=false;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    int n = 10;
    vector<vector<int>> ans = s.findPrimePairs(n);
    for(auto &v: ans) {
        cout << v[0] << " " << v[1] << endl;
    }
    return 0;
}