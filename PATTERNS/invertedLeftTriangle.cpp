#include<bits/stdc++.h>
using namespace std;
// Print Inverted Left Triangle
void invertedLeftTriangle(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    invertedLeftTriangle(n);
    return 0;
}