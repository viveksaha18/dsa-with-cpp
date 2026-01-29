#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] > nums[st.top()]) {
                int prev = st.top();
                st.pop();
                res[prev] = i - prev;
            }
            st.push(i);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    for(int days : result) {
        cout << days << " ";
    }
    return 0;
}