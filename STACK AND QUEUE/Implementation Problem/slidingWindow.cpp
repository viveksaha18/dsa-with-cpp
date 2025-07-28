#include<bits/stdc++.h>
using namespace std;

/*
Quesion :
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/


// Brute Force Approach 
vector<int> slidingWindow_BruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0; i <= n - k; i++) {
        int maxEle = nums[i];
        for(int j = i; j < i + k && j < n; j++) {
            maxEle = max(maxEle, nums[j]);
        }
        ans.push_back(maxEle);
    }
    return ans;
}



/*
Optimal Approach 
Here in this problem we use deque because to optimize the time complexity. We have to solve this problem in linear time complexity.
So, first we need to solve this problem in linear time then we need to track of k elements in the window, which would be the maximum also.
for that purpose we will use deque, because it allows  insertion and deletion in both the ends in O(1) time complexity.
*/

vector<int> slidingWindow_Optimal(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> ans; 
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        // track of k elements like i - k index will say that this element is out of the window . means the idx is i - k and if dq.front() <= i - k then pop out 
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();

        // track of maximum element in the window, if the dq.back <= nums[i] then pop out no need if we get greater one
        while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) ans.push_back(nums[dq.front()]); // when we reach the window size k then we can push the front element of deque which is the maximum element in the current window
    } 
    return ans;
}
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> bruteForce_Ans = slidingWindow_BruteForce(nums, k);
    for(auto it : bruteForce_Ans) {
        cout << it << " ";
    }

    cout << endl;
    vector<int> optimal_Ans = slidingWindow_Optimal(nums, k);
    for(auto it : optimal_Ans) {
        cout << it << " ";
    }
    return 0;
}