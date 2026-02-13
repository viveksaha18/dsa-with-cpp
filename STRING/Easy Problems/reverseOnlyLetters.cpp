#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string engLetters="";
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                engLetters.push_back(s[i]);
            }
        }
        reverse(engLetters.begin(), engLetters.end());
        int j = 0;
        for(int i = 0; i < s.size()&&j<engLetters.size(); i++) {
             if(isalpha(s[i])) {
                s[i]=engLetters[j];
                j++;
            }
        }
        return s;
    }
};
int main() {
    Solution s;
    string str = "ab-cd";
    cout << s.reverseOnlyLetters(str) << endl;
    return 0;
}