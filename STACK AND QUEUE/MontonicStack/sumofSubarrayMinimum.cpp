#include<bits/stdc++.h>
using namespace std;
/*
Question : https://leetcode.com/problems/sum-of-subarray-minimums/description/

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

*/


/*
Brute Force Approach : Finding all the subarrays and sum up their minimums 
Time Complexity : O(n2) and Space Complexity : O(1)
*/
long long sumofSubarrayMinimum_Brute(vector<int> arr) {
    int n = arr.size();
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        int minElement = arr[i];
        for(int j = i; j < n; j++) {
            minElement = min(minElement, arr[j]);
            sum += minElement;
        }
    }
    return sum;
}

/*
Optimal Approach : 
Like for reducing time complexity we probably do it in one pass, for that we have to know an element will be smaller for how many subarrays.
So, we can say like if an element to be smaller in a subarray when we have its nextSmaller and previous smaller element then we can assurely say,
how many subarrays would the element will have . 

Time Complexity : 
*/



vector<int> findNextSmaller(vector<int>& arr, int n){
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
        }
            res[i] = st.empty() ? n : st.top();
            st.push(i);
    }
    return res;
}

vector<int> findPreSmaller(vector<int>& arr, int n){
    vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    return res;
}





long long sumofSubarrayMinimum_Optimal(vector<int> arr) {
    int n = arr.size();
    vector<int> nSmaller = findNextSmaller(arr,n);
    vector<int> preSmaller = findPreSmaller(arr,n);
    int total = 0;
    int mod = (int)(1e9 + 7);
    for(int i = 0; i < arr.size(); i++){
        int left = i - preSmaller[i];
        int right = nSmaller[i] - i;
        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }
    return total;
}
int main() {
    vector<int> arr = {3, 1, 2, 4};
    long long bruteAns = sumofSubarrayMinimum_Brute(arr);
    cout << bruteAns << endl;
    long long optimalAns = sumofSubarrayMinimum_Optimal(arr);
    cout << optimalAns << endl;
    return 0;
}