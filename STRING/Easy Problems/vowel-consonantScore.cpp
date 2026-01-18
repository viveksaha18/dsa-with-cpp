#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        int v = 0,  c = 0;
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            ch = tolower(ch);
            if(ch >= 'a' && ch <= 'z') {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    v++;
                }
                else c++;
            }
        }
        if(c == 0) return 0;
        return floor(v/c);
    }
};
int main() {
    Solution s;
    string str = "aeioubcdfg";
    cout << s.vowelConsonantScore(str) << endl;
    return 0;
}