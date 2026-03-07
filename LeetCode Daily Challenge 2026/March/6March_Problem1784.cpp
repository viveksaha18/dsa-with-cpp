#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool check(int idx, string& s) {
    int n = s.size();
    for(int i = idx+1; i < n; i++) {
        if(s[i] == '1') return true;
    }
    return false;
}
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(check(i, s)) {
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};
int main() {
    Solution s;
    string str = "1001";
    cout << s.checkOnesSegment(str) << endl;
    return 0;
}