#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol =  {0, 1, 0, -1};
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
    vis[row][col] = 1;
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
            dfs(nrow, ncol, vis, board);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // visited matrix 
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverese throught the boundary of the board where we found O
        // row 
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board);
            }
        }

        // col
        for(int i = 0; i < n; i++) {
        
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main() {
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution s;
    s.solve(board);
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}