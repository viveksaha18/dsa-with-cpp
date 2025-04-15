#include<bits/stdc++.h>
using namespace std;

// we have to find the sum of the digit up to n using recursion 


int printSum(int n){
    if( n == 1) return 1;
    return n+printSum(n - 1);
}
int main(){
    int n;
    cout << "Enter the number" << endl;
    cin >> n;

    int ans = printSum(n);
    cout << "The sum of the numbers of 1 to n is : " << ans << endl;
    return 0;
}