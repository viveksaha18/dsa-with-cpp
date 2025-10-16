#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/non-overlapping-intervals/description/"
class Solution {
public:
static bool comp(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int lastTime = intervals[0][1];
        for(int i = 1; i <= n-1; i++) {
            if(intervals[i][0] >= lastTime) {
                cnt++;
                lastTime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};
int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    Solution s;
    cout << s.eraseOverlapIntervals(intervals);
    return 0;
}