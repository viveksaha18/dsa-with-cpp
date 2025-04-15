#include<bits/stdc++.h>
using namespace std;

/*
Steps


1. Iterate over the string where u found a operator then remove top1 and top 2 and then remove them and push 
'(' + top2 + operator + top1 ')
ab-de+f* /

i       st
a        a
b       a,b
-       (a-b)
d       (a-b),d
e       (a-b),d,e
+       (a-b),(d+e)
f       (a-b),(d+e),f
*       (a-b),((d+e)*f)
/       ((a-b)/((d+e)*f))  // output
*/
bool operand(char c){
    if((c >= 'A' && c <= 'Z') ||(c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            return true;
    }
    return false;
}


string postfixtoInfix(string s){
    int i = 0 , n = s.size();
    stack<string>st;
    while(i < n){
        if(operand(s[i])){
            string c = "";
            c+=s[i];
            st.push(c);
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            string con = '(' + t2 + s[i] + t1 + ')';
            st.push(con);
        }
        i++;
    }
    string ans = st.top();
    return ans;
}
int main(){

    string s = "ab-de+f*/";
    string Infix = postfixtoInfix(s);
    cout << Infix;
    return 0;
}