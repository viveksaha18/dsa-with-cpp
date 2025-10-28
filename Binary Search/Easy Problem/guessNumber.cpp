#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/guess-number-higher-or-lower/description/"
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int pick = 6;
int guess(int num) {
    if(num > pick) return -1;
    else if(num < pick) return 1;
    else return 0;
    return 0;
}
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) r = mid-1;
            else l = mid+1;
        }
        return 0;
    }
};
int main() {
    Solution s;
    int n = 10;
    int ans =  s.guessNumber(n);
    cout << ans;
    return 0;
}