#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
static bool cmp(int a, int b) {
    int bitsA = __builtin_popcount(a);
    int bitsB = __builtin_popcount(b);

    if(bitsA == bitsB) return a < b;
    return bitsA < bitsB;
}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
int main() {
    Solution s;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> ans = s.sortByBits(arr);
    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}