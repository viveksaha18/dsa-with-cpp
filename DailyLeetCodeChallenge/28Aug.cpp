#include<bits/stdc++.h>
using namespace std;

/*
Question : Sort matrix by diagonal
link : https://leetcode.com/problems/sort-the-matrix-diagonally/
*/
class Solution {
public:
void sortDiagonal(int row, int col, vector<vector<int>>& grid, bool orderofSorting, int& n) {
    int i = row, j = col;
    vector<int> ans;
    while(i < n && j < n) {
        ans.push_back(grid[i][j]);
        i++;
        j++;
    }
    if(orderofSorting) {
        sort(ans.begin(), ans.end());
    }
    else sort(ans.rbegin(), ans.rend());
    i = row;
    j = col;
    for(int& val : ans) {
        grid[i][j] = val;
        i++;
        j++;
    }
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
 
        // bottom left
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false, n);
        }
        // right
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true, n);
        }
        return grid;
    }
};
int main() {
    Solution s;
    vector<vector<int>> grid = {{1,7,3},{9,8,3},{4,6,5}};
    vector<vector<int>> ans = s.sortMatrix(grid);
    for(auto& row : ans) {
        for(auto& val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}