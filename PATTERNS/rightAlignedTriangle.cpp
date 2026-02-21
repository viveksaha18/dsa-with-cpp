#include<bits/stdc++.h>
using namespace std;
void rightAlignedTriangle(int n) {
    int k = n-1;
    for(int i = 1; i <= n; i++) {
        // spaces
        for(int z = 1; z <= k; z++) {
            cout << " ";
        }
        k-=1;
        // star
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    rightAlignedTriangle(n);
    return 0;
}