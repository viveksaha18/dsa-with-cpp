// Problem link : "https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/"

/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function(n) {
    let arr = [];
    for(let i = 1; i <= n/2; i++) {
        arr.push(i);
        arr.push(-i);
    }
    if(n%2 != 0) arr.push(0);
    return arr;
};

console.log(sumZero(5));