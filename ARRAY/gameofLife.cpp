#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

vector<vector<int>> dirs = {
    {-1,-1}, {-1,0}, {-1,1},
    {0,-1},          {0,1},
    {1,-1}, {1,0}, {1,1}
};
int countNeighbours(int i, int j, vector<vector<int>>& board, int n, int m) {
    int live = 0;
    for (auto &d : dirs) {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 && r < n && c >= 0 && c < m) {
                live += board[r][c];
            }
        }

    return live;
}
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int live = countNeighbours(i, j, board, n, m);
                if(board[i][j] == 1) {
                    if(live == 2 || live == 3) {
                        ans[i][j] = 1;
                    }
                }
                else {
                    if(live == 3) {
                        ans[i][j] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j]  = ans[i][j];
            }
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    sol.gameOfLife(board);
    for(auto &row : board) {
        for(auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}