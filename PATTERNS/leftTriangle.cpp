#include<bits/stdc++.h>
using namespace std;
// Print Left Triangle
void printLeftTriangle(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    printLeftTriangle(n);
    return 0;
}