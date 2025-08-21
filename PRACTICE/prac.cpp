#include<bits/stdc++.h>
using namespace std;
 vector<char> reverseString(vector<char>& s) {
        vector<char> t(s.size(), '$');
        int i = 0;
        for(int k = s.size() - 1; k >= 0; k--) {
            t[i] = s[k];
            i++;
        }
        return t;
}
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    vector<char> t = reverseString(s);
    for(char c : t) {
        cout << c << " ";
    }
    return 0;
}