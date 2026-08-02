#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string getSubstring(stack<char>& st) {
    string t = "";
    while(st.top() != '[') {
        t = st.top() + t;
        st.pop();
    }
    st.pop();
    return t;
}

bool isDigit(char c) {
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || 
    c == '8' || c == '9') return true;
    return false;
}
void updatedStack(stack<char>& st, int actualNumber, string t) {
     for(int i = 0; i < actualNumber; i++) {
        for(char c : t) {
            st.push(c);
        }
    }
}
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else {
                // we got a closing bracket 
                string t = getSubstring(st);
                string num = "";
                while(!st.empty() && isDigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }
                int actualNumber = stoi(num);
                // append in the string 
                updatedStack(st, actualNumber, t);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
int main() {
    Solution s;
    cout << s.decodeString("3[a2[c]]") << endl;
    return 0;
}