#include<bits/stdc++.h>
using namespace std;
/*
Question :
Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:

Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
*/

int f(int day, int lastIdx, vector<vector<int>>& arr, vector<vector<int>>& dp) {

    if(day == 0) {
        int maxi = 0;
        for(int i = 0; i <= 2; i++) {
            if(i != lastIdx) maxi = max(maxi, arr[0][i]);
        }
        return maxi;
    }
    if(dp[day][lastIdx] != -1) return dp[day][lastIdx];
    int maxi =  0;
    for(int i = 0; i <= 2; i++) {
        if(i != lastIdx)
            maxi = max(maxi, arr[day][i] + f(day - 1, i, arr, dp));
    }
    return dp[day][lastIdx] = maxi;
}
int main() {
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int lastIdx = 3;
    cout << f(n - 1, lastIdx, arr, dp) << endl;
    dp.clear();
    dp.resize(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);

    for(int day = 1; day < n; day++) {
        for(int lastIdx = 0; lastIdx < 4; lastIdx++) {
            dp[day][lastIdx] = 0;
            for(int i = 0; i <= 2; i++) {
                if(i != lastIdx)
                    dp[day][lastIdx] = max(dp[day][lastIdx], arr[day][i] + dp[day - 1][i]);
            }
        }
    }
    cout <<  dp[n - 1][3] << endl;

    // Space Optimization
    vector<int> prev(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
     for(int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++) {
                temp[last] = 0;
                for(int i = 0; i <= 2; i++) {
                    if(i != last) {
                       temp[last] =  max(temp[last], arr[day][i] + prev[i]);
                    }
                }
            }
        prev = temp;
    }
    
    cout << prev[3] << endl;
    return 0;
}