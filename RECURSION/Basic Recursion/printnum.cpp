#include<bits/stdc++.h>
using namespace std;

// we have to print numbers from n to 1 using recursion


void printNum(int n){
    if(n == 1){
        cout << n;
        return;
    }
    // cout << n;  // This will print from n to 1
    printNum(n - 1);
    cout << n;  // This will from 1 to n 
}
int main(){
    int n; 
    cout << "Enter any number " << endl;
    cin >> n;

    printNum(n);
    return 0;
}