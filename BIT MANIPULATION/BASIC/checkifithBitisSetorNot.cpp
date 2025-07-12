#include<bits/stdc++.h>
using namespace std;        

/*
Problem Statement : Given two positive integer n and  k, check if the kth index bit of n is set or not.
 Note: A bit is called set if it is 1. 

Examples : 

Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
Input: n = 500, k = 3
Output: false
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.
*/
// Brute Force Approach Time Complexity: O(log n) for converting to binary, Space Complexity: O(log n) for storing binary representation
bool bruteForce(int n, int k){
     string res = "";
    while(n > 0){
        if(n % 2 == 1) res+='1';
        else res+='0';
        n/=2;
    }
    reverse(res.begin(),res.end());
    if(k >= res.size()) return false; // if k is out of bounds
    return res[res.size() - 1 - k] == '1'; // check if the kth bit is set
}
// Optimal Approach using Bit Manipulation Time Complexity: O(1), Space Complexity: O(1)
bool optimal(int n, int k){
    return (n & (1 << k)) != 0; // check if the kth bit is set using bitwise AND
}
int main(){
    int n = 4 , k = 2;
    bool ans = bruteForce(n,k);
    cout << ans << endl;
    bool ans2 = optimal(n,k);
    cout << ans2 << endl;
    return 0;
}