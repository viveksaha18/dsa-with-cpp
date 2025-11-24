#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& t : tokens) {
            if(t == "+" || t == "-" || t == "*" || t == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res = 0;
                if(t == "+") {
                    res = b + a;
                }
                else if(t == "-") {
                    res = b - a;
                }
                else if(t == "*") {
                    res = b * a;
                }
                else res = b / a;

                st.push(res);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
int main() {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(tokens) << endl; // Output: 9
    return 0;
}