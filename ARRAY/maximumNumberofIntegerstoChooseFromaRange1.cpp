#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(), banned.end());
        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(st.find(i) != st.end()) continue;
            if(sum+i > maxSum) break;
            sum += i;
            cnt++;
        }
        return cnt;
    }
};
int main() {
    return 0;
}