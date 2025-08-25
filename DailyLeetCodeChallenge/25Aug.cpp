#include<bits/stdc++.h>
using namespace std;

/*
Question: 
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
*/



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> mpp;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for(auto &it : mpp) {
            if(flip) {
                reverse(it.second.begin(), it.second.end());
            }
            for(int &num : it.second) {
                ans.push_back(num);
            }
            flip = !flip;
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = s.findDiagonalOrder(mat);
    for(int &num : ans) {
        cout << num << " ";
    }
    
    return 0;
}