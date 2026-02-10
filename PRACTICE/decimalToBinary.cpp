#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string s) {
   int n = 0;
   int len = s.size();
   for(int i = len-1; i >= 0; i--) {
       if(s[i] == '1') {
           n += pow(2, len-1-i);
       }
   }
   return n;
}
int main() {
    string s;
    cin >> s;
    int deci = binaryToDecimal(s);
    cout << deci;
    return 0;
}