#include<bits/stdc++.h>
using namespace std;
/*
Question:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
vector<string> ans;
void f(int idx, string& temp, string& digits, unordered_map<char, string>& mpp) {

    // base case 
    if(idx >= digits.size()) {
        ans.push_back(temp);
        return;
    }
    char ch = digits[idx];
    string str = mpp[ch];
    for(int i = 0; i < str.size(); i++) {
        temp.push_back(str[i]);
        f(idx + 1, temp, digits, mpp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string temp;
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        f(0, temp, digits, mpp);
        return ans;
    }
};
int main() {
    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    for(auto &it : ans) {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}