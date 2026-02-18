#include<bits/stdc++.h>
using namespace std;
int f(int n) {
    return 1 << n;
}
int main() {
    int n = 2;
    int powerofTwo = f(2);
    cout << powerofTwo << endl;
    return 0;
}