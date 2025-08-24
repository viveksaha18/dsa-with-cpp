/*

Medium
Topics
premium lock icon
Companies
Hint
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

// Solution 
// Time Complexity : O(n)
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let n = nums.length
    if(n === 0) return 0;
    let prev = 0, curr = 0, maxCnt = 0;
    for(let i = 0; i < n; i++) {
        if(nums[i] === 1) curr++;
        else{
            maxCnt = Math.max(maxCnt, curr + prev);
            prev = curr;
            curr = 0;
        }
    }
    maxCnt =  Math.max(maxCnt, curr + prev);
    if(maxCnt === n) return n - 1
    return maxCnt;
};


console.log(longestSubarray([1,1,0,1])); // Output: 3