#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {{-5}};
    int k = 1;
    int ele = s.kthSmallest(matrix, k);
    cout << ele;
    return 0;
}