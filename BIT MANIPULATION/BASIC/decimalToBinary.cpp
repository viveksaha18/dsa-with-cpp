#include<bits/stdc++.h>
using namespace std;
string decimalToBinary(int n) {
    if(n == 0) return "0";
    string s;
    while(n > 0) {
        if(n % 2 != 0) {
            s += '1';
        }
        else s += '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    string num = decimalToBinary(n);
    cout << "The number is :" << num << endl;
    return 0;
}