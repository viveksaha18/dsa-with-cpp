#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "a#b%*";
    int k = 1;
    string result = "";
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                result += c;
            } 
            else if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } 
            else if (c == '#') {
                result += result;
            } 
            else if (c == '%') {
                reverse(result.begin(), result.end());
            }
        }

        
         // Return k-th character or '.' if out of bounds
        if (k >= 0 && k < result.size()) {
            cout << 'result[k]';
        } else {
            cout <<  '.';
        }
    return 0;
}