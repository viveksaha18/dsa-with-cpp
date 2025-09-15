#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
unordered_set<char> st;
bool check(string str) {
    for(char& c : str) {
        if(st.find(c) != st.end()) {
            return false;
        }
    }
    return true;
}
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt = 0;
        for(char &c : brokenLetters) {
            st.insert(c);
        }
        vector<string> temp;
        string word;
        stringstream ss(text);
        while(ss >> word) {
            temp.push_back(word);
        }
        for(string str : temp) {
            if(check(str)) cnt++;
        }
        return cnt;
    }
};
int main() {
    string text = "hello world";
    string brokenLetters = "ad";
    Solution s;
    int ans = s.canBeTypedWords(text, brokenLetters);
    cout << ans;
    return 0;
}