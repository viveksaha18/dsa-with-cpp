#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/vowels-game-in-a-string/"
class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        return cnt > 0;
    }
};
int main() {
    string str = "leetcode";
    Solution s;
    bool isTrue = s.doesAliceWin(str);
    if(isTrue) {
        cout << "True";
    }
    else cout << "False";
    return 0;
}