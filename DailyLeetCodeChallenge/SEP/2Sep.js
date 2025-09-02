// Question : Find the number of places to place the people |

/*
You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border).
Return the count.

 

Example 1:

Input: points = [[1,1],[2,2],[3,3]]

Output: 0

Explanation:



There is no way to choose A and B so A is on the upper left side of B.

Example 2:

Input: points = [[6,2],[4,4],[2,6]]

Output: 2

Explanation:



The left one is the pair (points[1], points[0]), where points[1] is on the upper left side of points[0] and the rectangle is empty.
The middle one is the pair (points[2], points[1]), same as the left one it is a valid pair.
The right one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0], but points[1] is inside the rectangle so it's not a valid pair.
Example 3:

Input: points = [[3,1],[1,3],[1,1]]

Output: 2

Explanation:



The left one is the pair (points[2], points[0]), where points[2] is on the upper left side of points[0] and there are no other points on the line they form. Note that it is a valid state when the two points form a line.
The middle one is the pair (points[1], points[2]), it is a valid pair same as the left one.
The right one is the pair (points[1], points[0]), it is not a valid pair as points[2] is on the border of the rectangle.
 

Constraints:

2 <= n <= 50
points[i].length == 2
0 <= points[i][0], points[i][1] <= 50
All points[i] are distinct.
 

*/
/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfPairs = function(points) {
    let n = points.length
    let ans = 0
    for(let i = 0; i < n; i++) {
        let cx = points[i][0], cy = points[i][1]
        for(let j = 0; j < n; j++) {
            let tx = points[j][0], ty = points[j][1]
            if(i == j || cx > tx || ty > cy) continue
            let flag = true
            for(let k = 0; k < n; k++) {
                if(k == i || k == j) continue
                if(points[k][0] >= cx && points[k][0] <= tx && points[k][1] >= ty && points[k][1] <= cy) flag = false
            }
            if(flag) ans++;
        }
    }
    return ans;
};

console.log(numberOfPairs([[6,2],[4,4],[2,6]]))
