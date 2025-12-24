#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini = INT_MAX;
        for(auto it : tasks) {
            int first = it[0];
            int second = it[1];
            int sum = first + second;
            mini = min(mini, sum);
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};
int main() {
    Solution s;
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2}};
    cout << "The earliest time to finish one task is: " << s.earliestTime(tasks) << endl;
    return 0;
}