#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/01-matrix/"
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> result(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && result[nrow][ncol] == -1) {
                    result[nrow][ncol] = result[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> ans = s.updateMatrix(mat);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}