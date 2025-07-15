#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach : Time Complexity : O(n) , Space Complexity : O(1)
string bruteApproach(int n , int k){
    string ans = "";
    while(n > 0){
        if(n % 2 == 1) ans+='1';
        else ans+='0';
        n/=2;
    }
    if(ans[k] == '0') ans[k] =  '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

// Optimal Approach : Time Complexity : O(1) , Space Complexity : O(1)
string optimalApproach(int n , int k){
    // first of all we have to create a mask for the ith bit by doing left shifing operation 1 << k
    int number = n | (1 << k);;
    string ans = "";
    while(number > 0){  
        if(number % 2 == 1) ans+='1';
        else ans+='0';
        number/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n = 9;
    int k = 2;
    // Question says set the ith bit like in this question we have to set the ith bit of n which is basically if the bit is zero than set as one , if it is one than not do anyting
    string bruteans = bruteApproach(n,k);
    cout << bruteans;
    cout << endl;
    string optimalans = optimalApproach(n,k);
    cout << optimalans << endl;
    return 0;
}