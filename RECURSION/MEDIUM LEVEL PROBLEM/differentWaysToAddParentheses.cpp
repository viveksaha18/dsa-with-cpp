#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        for(int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*') {
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i+1);
                vector<int> left = diffWaysToCompute(leftPart);
                vector<int> right = diffWaysToCompute(rightPart);
                for(int l : left) {
                    for(int r : right) {
                        if(c == '+') result.push_back(l+r);
                        else if(c == '-') result.push_back(l-r);
                        else result.push_back(l*r);
                    }
                }
            }
        }
        if(result.empty()) {
            result.push_back(stoi(expression));
        }
        return result;
    }
};
int main() {
    Solution sol;
    string expression = "2*3-4*5";
    vector<int> ans = sol.diffWaysToCompute(expression);
    for(int i : ans) {
        cout << i << " ";
    }
    return 0;
}