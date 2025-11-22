/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let nofOperations = 0;
    let n = nums.length;
    for(let i = 0; i < n; i++) {
        if(nums[i] % 3 != 0) {
            nofOperations++;
        }
    }
    return nofOperations;
};

// Example usage:
console.log(minimumOperations([1,2,3,4,5,6]));