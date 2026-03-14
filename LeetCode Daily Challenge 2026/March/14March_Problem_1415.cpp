#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void f(string s, vector<string>& res, int n) {
    if(s.size() == n) {
        res.push_back(s);
        return;
    }

    for(char c : {'a', 'b', 'c'}) {
        if(s.empty() || s.back() != c) {
            f(s+c, res, n);
        }
    }
}
    string getHappyString(int n, int k) {
        vector<string> res;
        f("", res, n);
        if(k > res.size()) return "";
        return res[k-1];
    }
};
int main() {
    Solution sol;
    cout << sol.getHappyString(3, 9) << endl;
    return 0;
}