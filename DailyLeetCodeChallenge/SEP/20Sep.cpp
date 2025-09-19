#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/design-spreadsheet/"
class Spreadsheet {
public:
vector<vector<int>> spread;
    Spreadsheet(int rows) {
        spread.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1)) - 1;

        spread[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1)) - 1;
        spread[row][col] = 0;
    }
    int solve(string s) {
        if(isdigit(s[0])) {
            return stoi(s);
        }
        int col = s[0]-'A';
        int row = stoi(s.substr(1)) - 1;
        return spread[row][col];
    }
    int getValue(string formula) {
        string s = formula.substr(1);
        int plusIdx = s.find('+');
        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx+1);
        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
int main() {
    Spreadsheet* obj = new Spreadsheet(5);

    obj->setCell("A1", 10);
    obj->setCell("B1", 20);
    obj->setCell("C1", 5);

    cout << "A1 = 10, B1 = 20, C1 = 5\n";
    cout << "Formula '=A1+B1' -> " << obj->getValue("=A1+B1") << endl;
    cout << "Formula '=A1+15' -> " << obj->getValue("=A1+15") << endl;
    cout << "Formula '=A1+B1+C1' -> " << obj->getValue("=A1+B1+C1") << endl;

    obj->resetCell("A1");
    cout << "After reset A1, formula '=A1+B1' -> " << obj->getValue("=A1+B1") << endl;

    delete obj;
    return 0;
}