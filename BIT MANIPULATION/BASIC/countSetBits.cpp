#include<bits/stdc++.h>
using namespace std;
/*
Question: Count the number of set bits in an integer.
*/

int countBits(int n){
    int cnt = 0;
    while(n > 0){
        if(n & 1 == 1) cnt++;
        n = n >> 1; // Right shift the bits of n by 1
    }
    return cnt;
}
int main(){
    int n = 13;
    int nofBits = countBits(n);
    cout << nofBits << endl;
    return 0;
}