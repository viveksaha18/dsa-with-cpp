#include<bits/stdc++.h>
using namespace std;
// Leetcode Problem Link : "https://leetcode.com/problems/maximum-units-on-a-truck/description/"
class Solution {
public:
static bool comp(vector<int> a, vector<int> b) {
    int a1 = a[1];
    int b1 = b[1];
    return a1 > b1;
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for(int i = 0; i < n; i++) {
            if(boxTypes[i][0] <= truckSize) {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
 
};
int main() {
    Solution s;
    vector<vector<int>> boxTypes = {{1, 3}, {2, 3}, {3, 1}};
    int truckSize = 4;
    cout << s.maximumUnits(boxTypes, truckSize);
    return 0;
}