#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool sameFreq(unordered_map<int, int>& mpp) {
    if(mpp.size()==1) return true;
    auto it = mpp.begin();
    int val =  it->second;
    for(auto it : mpp) {
        if(it.second != val) return false;
    }
    return true;
}
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            for(int j = i; j < n; j++) {
                mpp[s[j]]++;
                if(sameFreq(mpp)) {
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};
int main() {
    Solution s;
    string str = "aabbcc";
    cout << s.longestBalanced(str) << endl;
    return 0;
}