#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
int main() {
    Solution sol;
    vector<int> target = {1,2,3,4};
    vector<int> arr = {2,4,1,3};
    if(sol.canBeEqual(target, arr)) {
        cout << "The arrays can be made equal." << endl;
    } else {
        cout << "The arrays cannot be made equal." << endl;
    }
    return 0;
}