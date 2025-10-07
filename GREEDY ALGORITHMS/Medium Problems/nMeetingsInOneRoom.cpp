#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://www.geeksforgeeks.org/problems/n-meetings-in-one-room"
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
static bool comp(pair<int,int>& a, pair<int, int>& b) {
    int a1 = a.second;
    int b1 = b.second;
    return a1 < b1;
}
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>> res;
        for(int i = 0; i < n; i++) {
            res.push_back({start[i], end[i]});
        }
        sort(res.begin(), res.end(), comp);
        int cnt = 1;
        int endTime = res[0].second;
        for(int i = 1; i < n; i++) {
            if(res[i].first > endTime) {
                cnt++;
                endTime = res[i].second;
            }
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << s.maxMeetings(start, end);
    return 0;
}