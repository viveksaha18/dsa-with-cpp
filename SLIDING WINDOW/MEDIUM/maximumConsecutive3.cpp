/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/


#include<bits/stdc++.h>
using namespace std;

/*
Brute Force Solution : 
Generally we can the question as longest subarray with atmost k zeros , for that we can generate all the substrings and if they are valid.
Time Complexity : O(n2) and Space Complexity : O(1)
*/
int maxConsecutiveOnesBruteForce(vector<int> nums,int k){
    int n = nums.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        int zeros = 0;
        for(int j = i; j < n; j++){
            if(nums[j] == 0) zeros++;
            if(zeros > k) break;
            else{
                int len = j - i + 1;
                maxLen = max(maxLen,len);
            }
        }
    }
    return maxLen;
}
/*
Optimal Solution : Sliding Window Appraoch 
shrink the window when number of zeros is greater than k otherwise expands 
Time Complexity : O(N) + O(N) and Space Complexity : O(1)
*/
int maxConsecutiveOnesOptimal(vector<int> nums,int k){
    int n = nums.size();
    int maxLen = 0;
    int l = 0 , r = 0; // two pointers 
    int zeros = 0;
    while(r < n){
        if(nums[r] == 0) zeros++;
        // shrink
        while(zeros > k){ 
            if(nums[l] == 0) zeros--;
            l++;
        }
        int len = r - l + 1;
        maxLen = max(maxLen , len);
        r++;
    }
    return maxLen;
}


int maxConsecutiveOnes_Slightly_more_Optimal(vector<int> nums,int k){
    int n = nums.size();
    int maxLen = 0;
    int l = 0 , r = 0; // two pointers 
    int zeros = 0;
    while(r < n){
        if(nums[r] == 0) zeros++;
        // shrink
        if(zeros > k){ 
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
            int len = r - l + 1;
            maxLen = max(maxLen , len);
        }
        r++;
    }
    return maxLen;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int len = maxConsecutiveOnesBruteForce(nums,k);
    cout << len << endl;
    int maxLen = maxConsecutiveOnesOptimal(nums,k);
    cout << maxLen << endl;
    // slightly more optimal 
    int ans = maxConsecutiveOnes_Slightly_more_Optimal(nums,k);
    cout << ans << endl;
    return 0;
}