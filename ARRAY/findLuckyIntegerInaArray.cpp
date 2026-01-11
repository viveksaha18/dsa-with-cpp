#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi = -1;
        unordered_map<int, int> mpp;
        for(int x : arr) {
            mpp[x]++;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == mpp[arr[i]]) {
                maxi = max(maxi, arr[i]);
            }
        }
        return maxi;
    }
};
int main() {
    Solution s;
    vector<int> arr = {2,2,3,4};
    int ans = s.findLucky(arr);
    cout << ans << endl;
    return 0;
}