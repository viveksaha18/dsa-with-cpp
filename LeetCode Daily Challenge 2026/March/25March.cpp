#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool horizontal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long totalSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                totalSum += grid[i][j];
            }
        }

        long long topSum = 0;
        for(int i = 0; i < n - 1; i++) { 
            for(int j = 0; j < m; j++) {
                topSum += grid[i][j];
            }
            if(topSum == totalSum - topSum) return true;
        }

        return false;
    }

    bool vertical(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long totalSum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                totalSum += grid[i][j];
            }
        }

        long long leftSum = 0;
        for(int j = 0; j < m - 1; j++) {  
            for(int i = 0; i < n; i++) {
                leftSum += grid[i][j];
            }
            if(leftSum == totalSum - leftSum) return true;
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        return horizontal(grid) || vertical(grid);
    }
};
int main() {
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution sol;
    bool result = sol.canPartitionGrid(grid);
    cout << (result ? "true" : "false") << endl;
    return 0;
}