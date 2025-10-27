#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string s) {
    int n = 0;
    int len = s.size()-1;
    for(int i = len; i >= 0; i--) {
        if(s[i] == '1') {
            n = n + pow(2, len-i);
        }
    }
    return n;
}
int main() {
    string s = "111";
    int n = binaryToDecimal(s);
    cout << n;
    return 0;
}