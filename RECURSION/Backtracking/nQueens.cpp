#include<bits/stdc++.h>
using namespace std;
/*

    Problem Statement : 
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

*/


bool isSafe(vector<string> &board, int row , int col , int n){
    for(int i = 0; i < n;i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // for vertical 
    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // for left diagonal

    for(int i = row ,   j = col ; i >= 0 && j >= 0 ; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // for right diagonal
    for(int i = row ,   j = col ; i >= 0 && j < n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void nQueens(vector<string> &board, vector<vector<string>> &ans, int row , int n){
    if(row == n){
        ans.push_back({board}); 
        return; 
    }
    for(int j = 0; j < n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            nQueens(board,ans,row+1,n);
            board[row][j] = '.'; // backtracking
        }
    }
}
int  main(){
    int n = 4 ;

    // Here n is the number of queens 

    vector<string>board(n,string(n,'.'));
    vector<vector<string>> ans;
    
    nQueens(board,ans,0,n);
    for(auto it : ans){
        cout << "[";
        for(auto i : it){
            cout << i <<" " << ",";
        }
        cout << " ] " << endl;
    }
    return 0;

}