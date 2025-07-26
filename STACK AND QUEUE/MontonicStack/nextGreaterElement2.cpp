#include<bits/stdc++.h>
using namespace std;
/*
Question :
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
*/


// Brute Force Approach 
vector<int> nextGreaterElementBruteForce(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
        for(int k = 0; k < i; k++) {
            if(arr[k] > arr[i]) {
                ans[i] = arr[k];
                break;
            }
        }
    }
    return ans;
}


// Better Approach using double array approach 
vector<int> nextGreaterElementBetter(vector<int>& arr) {
    int n = arr.size();
    vector<int> nGreaterElement(n, -1);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <n + i; j++) {
            int idx = j % n;
            if(arr[idx] > arr[i]) {
                nGreaterElement[i] = arr[idx];
                break;
            }
        }
    }
    return nGreaterElement;
}


// Optimal Approach using stack 
vector<int> nextGreaterElementOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> nGreaterElement(n,0);
    stack<int> st;
    for(int i = 2 * n - 1; i >= 0; i--) {
        // removing from the stack if the element in the stack is not probably smaller than the current Element 
        while(!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if(i < n) { // looking for the next greater element for that index as i < n 
            nGreaterElement[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return nGreaterElement;
}
int main(){
    vector<int> arr = {1,2,3,4,3};
    vector<int> bruteAns = nextGreaterElementBruteForce(arr);
    for(int i = 0; i < bruteAns.size(); i++){
        cout << bruteAns[i] << " ";
    }
    cout << endl;
    vector<int> betterAns = nextGreaterElementBetter(arr);
    for(int i = 0; i < betterAns.size(); i++) {
        cout << betterAns[i] << " ";
    }
    cout << endl;
    vector<int> optimalAns = nextGreaterElementOptimal(arr);
    for(int i = 0; i < optimalAns.size(); i++) {
        cout << optimalAns[i] << " ";
    }
    return 0;
}