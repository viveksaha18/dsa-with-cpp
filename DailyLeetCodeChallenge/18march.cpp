#include<bits/stdc++.h>
using namespace std;
/*
Question 
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
*/

int longestNiceSubarray(vector<int>& nums){
    int num = 0;
    
    int ans = 0;
    int j = 0;
    // Using Sliding Window Approach 
    for(int i = 0; i < nums.size(); i++){
        // if the bits not equal to zero then move the j pointer and donot conclude that element in the subarray
        while( (num & nums[i]) != 0){
            num^=nums[j++]; // unset the bits by using xor operator 
        }
        // if the & is zero then we got the subarray 
        // just add with the current number which is nums[i] 
        num |= nums[i];
        ans = max(ans , (i - j + 1));
    }
    return ans;

}
int main(){

    vector<int> arr = {1,3,8,48,10};
    
    int ans = longestNiceSubarray(arr);
    cout << ans;
    return 0;
}