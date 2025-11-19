/**
 * @param {number[]} nums
 * @param {number} original
 * @return {number}
 */
var findFinalValue = function(nums, original) {
    let n = nums.length;
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < n; j++) {
            if(nums[j] == original) {
                original = 2*original;
            }
        }
    }
    return original;
};

let nums = [5,3,6,1,12], original = 3;
console.log(findFinalValue(nums, original));