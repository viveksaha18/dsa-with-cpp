#include<bits/stdc++.h>
using namespace std;

/*

Conversion of Infix Operation to a Postfix expression 

Infix expression means a+b operand operator operand
Postfix expression means ab+ operand operand operator 




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
string InfixtoPostfix(string s){
    stack<char>st;
    string ans = ""; //stores the postfix expression 
    int n = s.size();
    int i = 0;
    while(i < n){
        if(operand(s[i])){
            ans+=s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{ // here i got a operator 

            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    // other remaining operators 

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){

    string s = "a+b*(c^d-e)";

    string postFix = InfixtoPostfix(s);
    cout << postFix << endl;
    
    return 0;
}