#include<bits/stdc++.h>
using namespace std;
// Problem link : "https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/"
class Solution {
public:
long long solve(long long l, long long r) {
    long long L = 1;
    long long S = 1;
    long long steps = 0;
    while(L <= r) {
        long long R = L*4 - 1;
        long long start = max(L, l);
        long long end = min(R, r);
        if(start <= end) {
            steps += (end - start+1) * S;
        }
        S++;
        L = L*4;
    }
    return steps;
}
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for(auto query : queries) {
            long long l = query[0];
            long long r = query[1];
            long long steps = solve(l, r);
            result += (steps+1)/2;
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int>> queries = {{1,2},{2,4}};
    cout << s.minOperations(queries);
    return 0;
}