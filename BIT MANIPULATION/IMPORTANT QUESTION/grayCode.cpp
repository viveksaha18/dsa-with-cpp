#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int z = pow(2, n);
        vector<int> ans;
        for(int i = 0; i < z; i++) {
            ans.push_back(i ^ (i>>1));
        }
        return ans;
    }
};
int main() {
    Solution s;
    int n = 2;
    vector<int> ans = s.grayCode(n);
    for(int i : ans) {
        cout << i << " ";
    }
    return 0;
}