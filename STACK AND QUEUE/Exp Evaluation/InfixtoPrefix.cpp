#include<bits/stdc++.h>
using namespace std;

/*

Conversion of Infix Operation to a Prefix expression 

Infix expression means a+b operand operator operand
Postfix expression means +ab opertor operand operand 


Steps


1. Reverse the Infix 
2. Find Infix to Postfix 
3. Reverse the answer 

*/


bool operand(char c){
    if((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            return true;
    }
    return false;
}


int priority(char c){
    if(c == '^'){
        return 3;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}
string InfixtoPrefix(string s){
    reverse(s.begin(), s.end());

    // Swap brackets after reversing
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (operand(s[i])) {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        }
        else {
            while (!st.empty() && priority(s[i]) < priority(st.top())) {
                // right-associative
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){

    string s = "a+b*(c^d-e)";

    string preFix = InfixtoPrefix(s);
    cout << preFix << endl;
    
    return 0;
}