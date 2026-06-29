#include<bits/stdc++.h>
using namespace std;
string reverseString(string& s) {
    int n = s.size();
    int i = 0, j = n-1;
    while(i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
int main() {
    string s;
    cin >> s;
    cout << reverseString(s);
    return 0;
}