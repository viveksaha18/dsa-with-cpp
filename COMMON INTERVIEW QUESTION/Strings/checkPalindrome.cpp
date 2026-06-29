#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& s) {
    int n = s.size();
    int i = 0, j = n-1;
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}
int main() {
    // madam 
    // madam 
    string s;
    cin >> s;
    cout << checkPalindrome(s);
    return 0;
}