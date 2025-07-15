#include<bits/stdc++.h>
using namespace std;
/*
Question : 
Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

Examples :

Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
Input: n = 15
Output: 31
Explanation: The binary representation of 15 is 01111. After setting right most bit it becomes 11111 which is 31.
*/
int unsetBit(int n){
    n = n | (n + 1); // It will set the rightmost unset bit 
    return n;
}
int main(){
    int n = 6;
    int ans = unsetBit(n);
    cout << ans << endl; // output 7
    return 0;
}