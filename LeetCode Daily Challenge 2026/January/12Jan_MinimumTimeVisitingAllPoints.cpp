#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int steps = 0;
        int n = points.size();
        for(int i = 0; i < n-1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];
            int dy = abs(y2-y1);
            int dx = abs(x2-x1);
            steps += min(dy, dx) + abs(dy-dx);
        }
        return steps;
    }
};
int main() {
    Solution s;
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    cout << s.minTimeToVisitAllPoints(points) << endl;
    return 0;
}