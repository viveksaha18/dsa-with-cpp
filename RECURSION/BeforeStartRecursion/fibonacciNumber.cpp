#include<bits/stdc++.h>
using namespace std;

// fibonacci series is series of numbers starting from 0,1,1,2,3,5,8
// To calulate the nth term we have to find tn = tn - 1 + tn - 2

/*
Time Complexity :

total calls * work in each call

It would be O((2n-1) * K)

Space Complexity : O(n)
*/
int fibonacciTerm(int n){

    if(n == 0 || n == 1) return n; // Base Case


    return fibonacciTerm(n -1) + fibonacciTerm(n - 2);
}
int main(){
    int n = 4;

    cout << fibonacciTerm(n) << endl;
    return 0;
}