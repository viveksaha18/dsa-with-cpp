#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool checkPeakElement(vector<vector<int>>& mat, int row, int col, int n, int m) {
    int val = mat[row][col];
    int left = -1;
    if(col-1 >= 0) {
        left = mat[row][col-1];
    }
    int right = -1;
    if(col+1 < m) {
        right = mat[row][col+1];
    }
    int top = -1;
    if(row-1 >= 0) {
        top = mat[row-1][col];
    }
    int bottom = -1;
    if(row+1 < n) {
        bottom = mat[row+1][col];
    }
    return (val > left && val > right && val > top && val > bottom);
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(checkPeakElement(mat, i, j, n, m)) return {i, j};
            }
        }
        return {-1, -1};
    }
};
int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> result = s.findPeakGrid(mat);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}