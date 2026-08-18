#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        queue<string> q;
        vector<string> ans;
        q.push("1");
        while(n--) {
            string s1 = q.front();
            q.pop();
            ans.push_back(s1);
            q.push(s1+"0");
            q.push(s1+"1");
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.generateBinary(5);
}