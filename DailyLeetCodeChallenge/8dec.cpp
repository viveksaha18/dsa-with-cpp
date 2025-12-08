#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= n; b++) {
                int c = a*a + b*b;
                int c2 = sqrt(c);
                if(c2 <= n && c2*c2 == c) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main() {
    Solution sol;
    int n = 5;
    int result = sol.countTriples(n);
    cout << result;
    return 0;
}