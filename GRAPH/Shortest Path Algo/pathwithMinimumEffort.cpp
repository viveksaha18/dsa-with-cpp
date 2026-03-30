#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0]=0;
        pq.push({0, {0, 0}});
        vector<int> dr={-1, 0, 1, 0};
        vector<int> dc={0, 1, 0, -1};
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int diff=p.first;
            int r=p.second.first;
            int c=p.second.second;
            if(r == n-1 && c == m-1) return diff;
            for(int i = 0; i < 4; i++) {
                int nrow = r+dr[i];
                int ncol = c+dc[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int newEffort = max(abs(heights[nrow][ncol]-heights[r][c]), diff);
                    if(newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol]=newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    cout << s.minimumEffortPath(heights) << endl;
    return 0;
}