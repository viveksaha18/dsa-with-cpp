#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n, vector<int>(n, 0));
       int left = 0, top = left, right = n-1, bottom = n-1;
       int num = 0;
       while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                ans[top][i] = ++num;
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                ans[i][right] = ++num;
            }
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans[bottom][i] = ++num;
                }
            }
            bottom--;
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans[i][left] = ++num;
                }
            }
            left++;
       }
       return ans;
    }
};
int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> matrix = sol.generateMatrix(n);
    for(auto &row : matrix) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}