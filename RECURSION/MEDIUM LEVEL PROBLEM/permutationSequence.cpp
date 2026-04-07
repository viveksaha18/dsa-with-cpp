#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++) {
            s.push_back(i +'0');
        }
        for(int i = 1; i < k; i++) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};
int main() {
    Solution s;
    cout << s.getPermutation(3, 3) << endl;
    return 0;
}