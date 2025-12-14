#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        int n = s.size();
        int k = n/4;
        if(mpp['Q'] <= k && mpp['R'] <= k && mpp['E'] <= k && mpp['W'] <= k) return 0;
        int l = 0, ans = n;
        for(int r = 0; r < n; r++) {
            mpp[s[r]]--;
            while(mpp['Q'] <= k && mpp['E'] <= k && mpp['R'] <= k && mpp['W'] <= k) {
                ans = min(ans, r-l+1);
                mpp[s[l]]++;
                l++;
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    string str = "WQWRQQQW";
    int res = s.balancedString(str);
    cout << res;
    return 0;
}