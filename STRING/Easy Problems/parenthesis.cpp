#include<bits/stdc++.h>
using namespace std;

// Question --> Remove Outermost Parentheses
// The goal of this function is to remove the outermost parentheses from every primitive valid parenthesis string in s.

//Input: "(()())(())"
//Output: "()()()"

void removeParenthesis(string s){
    string result;
    int cnt = 0;

    for(char c : s){
        if(c == '('){
            if(cnt > 0){
                result+=c;
            }
            cnt++;
        }
        else if(c == ')'){
            cnt--;
            if(cnt > 0) result+=c;
        }
    }
    cout<<result;
}
int main(){

    string s =  "(()())(())";
    removeParenthesis(s);

    return 0;
}