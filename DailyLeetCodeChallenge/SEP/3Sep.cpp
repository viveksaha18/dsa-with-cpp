#include<bits/stdc++.h>
using namespace std;

// Leetcode Link : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        auto cmp = [&](vector<int>& c, vector<int>& t) {
            if(c[0] == t[0]) return c[1] > t[1];
            return c[0] < t[0];
        };
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cx = points[i][0], cy = points[i][1];
            int k = -10000000000;
            for(int j = i + 1; j < n; j++) {
                int tx = points[j][0], ty = points[j][1];
                if(ty > cy) continue;
                if(ty > k) {
                    ans++;
                    k = ty;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<vector<int>> points = {{6,2},{4,4},{2,6}};
    cout << s.numberOfPairs(points) << endl;
    return 0;
}