#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
 const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int k = n*m;
        vector<int> a(k, 1);
        int z = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[z] = grid[i][j];
                z++;
            }
        }
        vector<int> prefix(k, 1);
        vector<int> suffix(k, 1);
        for(int i = 1; i < k; i++) {
            prefix[i] = ((long long)prefix[i-1]*a[i-1])%MOD;
        }
        for(int i = k-2; i >= 0; i--) {
            suffix[i] = ((long long)suffix[i+1]*a[i+1])%MOD;
        }
        z=0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = (prefix[z]*suffix[z])%MOD;
                z++;
            }
        }
        return grid;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<vector<int>> ans = s.constructProductMatrix(grid);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}