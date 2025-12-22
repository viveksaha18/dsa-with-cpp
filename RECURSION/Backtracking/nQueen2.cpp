#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isSafe(vector<string>& board, int row, int col, int n) {
    // horizontally
    for(int j = 0; j < n; j++) {
        if(board[row][j] == 'Q') return false;
    }
    // vertically
    for(int i = 0; i < n; i++) {
        if(board[i][col] == 'Q') return false;
    }
    // left diagonal 
    for(int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if(board[r][c] == 'Q') return false;
    }
    // right diagonal
     for(int i = row ,   j = col ; i >= 0 && j < n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
int f(vector<string>& board, int row, int n) {
    if(row == n) {
        return 1;
    }
    int ans = 0;
    for(int j = 0; j < n; j++) {
        if(isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            ans += f(board, row + 1, n);
            board[row][j] = '.';
        }
    }
    return ans;
}
    int solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return f(board, 0, n);
    }
    int totalNQueens(int n) {
        int ans = solveNQueens(n);
        return ans;
    }
};
int main() {
    Solution sol;
    int n = 4; // Example for 4-Queens problem
    cout << "Total solutions for " << n << "-Queens: " << sol.totalNQueens(n) << endl;
    return 0;
}