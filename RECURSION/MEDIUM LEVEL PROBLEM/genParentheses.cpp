#include<bits/stdc++.h>
using namespace std;

/*
Question: Generate all combinations of well-formed parentheses.
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

// Time complexity is O(2^(2n)) * O(n) for checking validity of parentheses
// Space complexity is O(n) for the recursion stack and O(n) for storing the result
class Solution {
public:
bool isValid(string temp) {
    int cnt = 0;
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
    }
    return cnt == 0;
}
void f(string& temp, vector<string>& ans, int n) {
    // base case
    if(temp.size() == 2 * n) {
        if(isValid(temp)) {
            ans.push_back(string(temp.begin(), temp.end()));
            return;
        }
        return;
    }
    temp.push_back('(');
    f(temp, ans, n);
    temp.pop_back();
    temp.push_back(')');
    f(temp, ans, n);
    temp.pop_back();
}
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        f(temp, ans, n);
        return ans;
    }
};



// Optimized version without checking validity of parentheses
// Time complexity is O(2n * valid combinations) 
// Space complexity is O(n) for the recursion stack and O(n) for storing the result
class Solution1 {
public:

void f(string& temp, vector<string>& ans, int n, int open, int close) {
    // base case
    if(close +  open == 2 * n) {
        
            ans.push_back(string(temp.begin(), temp.end()));
            return;
    }
    if(open < n) {
        temp.push_back('(');
        f(temp, ans, n, open + 1, close);
        temp.pop_back();
    }
    
    if(close < open) {
        temp.push_back(')');
        f(temp, ans, n, open, close + 1);
        temp.pop_back();
    }
    
}
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        
        f(temp, ans, n, 0, 0);
        return ans;
    }
};
int main() {

    Solution sol;
    int n = 2;
    vector<string> result = sol.generateParenthesis(n);
    for(const string& s : result) {
        cout << s << " ";
    }
    // Output: ["(())","()()"]
    cout << endl;

    Solution1 sol1;
    vector<string> result1 = sol1.generateParenthesis(n);
    for(const string& s : result1) {
        cout << s << " ";
    }
    // Output: ["(())","()()"]
    cout << endl;
    return 0;
}