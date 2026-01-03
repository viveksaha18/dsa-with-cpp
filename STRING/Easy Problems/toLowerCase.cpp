#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        string t = "";
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            t+=tolower(ch);
        }
        return t;
    }
};
int main() {
    Solution s;
    string str = "Hello World!";
    cout << s.toLowerCase(str) << endl;
    return 0;
}