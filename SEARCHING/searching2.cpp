#include<bits/stdc++.h>
using namespace std;


// Question 1
// Brute Force Approach 
// Using Linear Search 
// Time Complexity : O(n) and Space Complexity : O(1)
void squareRoot_Brute(int n){
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if( i*i <= n){
            ans = i;
        }
        else{
            break;       // if i*i exceeds than n so there is no number remain for squareroot of the given number 
        }
    }
    cout<<"The square root of the number is : " <<ans<<endl;
}

// Better Solution : Using sqrt() function 
void squareRoot_Better(int n){
    int ans = sqrt(n);
    cout<<"The square root of the number is : " <<ans<<endl;
}

// Optimal Solution : Using Binary Search
void squareRoot_Optimal(int n){
    int low = 1 , high = n , ans = 1;
    while( low <= high ){
        int mid = (low + high) / 2;
        if((mid * mid) <= n){
            ans = mid;
            low = mid + 1;   // Looking for further 
        }
        else{
            high = mid - 1;    // if mid * mid > n so no further mid in right side will be the sqrt of a number 
        }
    }
    cout<<"The square root of the number is : " <<ans<<endl;
}
int main(){

    //1. Square root of a number 
    // If it is not a perfect square then print its floor value like squareroot of 5 is 2.. so we have to print its floor value which is 2
    int n = 5;
    squareRoot_Brute(n);

    // For Better Solution 
    squareRoot_Better(n);

    // For Optimal One 
    squareRoot_Optimal(n);
    return 0;
}
