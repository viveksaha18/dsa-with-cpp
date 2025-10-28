#include<bits/stdc++.h>
using namespace std;
// Problem Link : "https://leetcode.com/problems/first-bad-version/"
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bad = 4;
bool isBadVersion(int num) {
    if(num == 4 || num > 5) return true;
    return false;
}
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        int ans = 0;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(isBadVersion(mid)) {
                ans = mid;
                r = mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
int main() {
    Solution s;
    int n = 5;
    int ans = s.firstBadVersion(n);
    cout << ans;
    return 0;
}