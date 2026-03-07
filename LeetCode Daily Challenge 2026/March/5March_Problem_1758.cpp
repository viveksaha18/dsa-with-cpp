#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        string s1 = "";
        string s2 = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                s1+='0';
                s2+='1';
            }
            else {
                s1+='1';
                s2+='0';
            }
        }
        int f1 = 0;
        int f2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != s1[i]) {
                f1++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != s2[i]) {
                f2++;
            }
        }
        return min(f1, f2);
    }
};
int main() {
    Solution s;
    string str = "0100";
    cout << s.minOperations(str) << endl;
    return 0;
}