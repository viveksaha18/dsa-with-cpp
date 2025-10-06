#include<bits/stdc++.h>
using namespace std;
// GFG Problem Link : "https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1"
class Solution {
  public:
  static bool comp(pair<int, int>& a, pair<int, int>& b) {
      double a1 = (1.0 * a.first)/a.second;
      double b1 = (1.0 * b.first)/b.second;
      return a1 > b1;
      
  }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<int, int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = {val[i], wt[i]};
        }
        sort(ans.begin(), ans.end(), comp);
        double res = 0.0;
        for(int i = 0; i < n; i++) {
            if(ans[i].second <= capacity) {
                res += ans[i].first;
                capacity -= ans[i].second;
            }
            else {
                res += (1.0 * ans[i].first / ans[i].second) * capacity;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> val1 = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << s.fractionalKnapsack(val1, wt, capacity);
    return 0;
}